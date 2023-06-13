#include "DifferentialEvolution.h"

DifferentialEvolution::DifferentialEvolution()
:mParameters{}
,mPopulation{}
,mMutant{}
,mTrial{}
,mCurrentGeneration{}
,mStatistics{}
,mSamplingTool{}
{
}


DifferentialEvolution::~DifferentialEvolution() 
{
}

DEParameters DifferentialEvolution::getParameters() const
{
	return mParameters;
}

size_t DifferentialEvolution::getCurrentGeneration() const
{
	return mCurrentGeneration;
}

bool DifferentialEvolution::isReady() const
{
	if (!mParameters.isReady()) {
		return false;
	}
	
	// Vérifie que mPopulation, mMutant et mTrial ont la bonne taille
	if (mPopulation.size() != mParameters.getPopulationSize() 
		|| mMutant.size() != mParameters.getPopulationSize() 
		|| mTrial.size() != mParameters.getPopulationSize()) {
		return false;
	}

	if (mCurrentGeneration != 1) {
		return false;
	}

	//vérifie si le vecteur mStatistics contient des données. si oui, retourne false
	if (!mStatistics.isEmpty()) {
		return false;
	}

	//if (mSamplingTool) {
	//	return false;
	//}

	return true;
}

void DifferentialEvolution::setup(DEParameters const& parameters)
{
	mSamplingTool.prepare(mParameters.getPopulationSize());
	mPopulation.setup(mParameters.getPopulationSize(), mParameters.getSolutionBounds());	
	mTrial.setup(mParameters.getPopulationSize(), mParameters.getSolutionBounds());
	mMutant.setup(mParameters.getPopulationSize(), mParameters.getSolutionBounds());

}  

void DifferentialEvolution::reset()
{
	// Réinitialisez la population de solutions
	mPopulation.setup(mParameters.getPopulationSize(), mParameters.getSolutionBounds());
	mPopulation.randomize(mParameters.getSolutionBounds());

	// Réinitialisez la population de mutants
	mMutant.setup(mParameters.getPopulationSize(), mParameters.getSolutionBounds());
	mMutant.randomize(mParameters.getSolutionBounds());

	// Réinitialisez la population de trial
	mTrial.setup(mParameters.getPopulationSize(), mParameters.getSolutionBounds());
	mTrial.randomize(mParameters.getSolutionBounds());


	// Réinitialisez génération
	mCurrentGeneration = 1;		//plus petit ou egal que

	// Réinitialisez les statistiques
	mStatistics.reset();


	// Réinitialisez l'outil d'échantillonnage
	mSamplingTool = ThreeSamplesWithOneExclusion();

	/*A TESTER POUR VERIFIER QUE TOUT SE REINITILAISE CORRECTEMENT*/
}

bool DifferentialEvolution::evolveOne()
{

	if (!isReady()) {
		return false;
	}

	//1) Évaluer la fitness de la population actuelle
	processFitness(mPopulation);
	
	//2) Effectuer la mutation des vecteurs
	processMutation();

	//3) Effectuer le croisement des vecteurs mutants avec les vecteurs de la population actuelle
	processCrossover();

	processFitness(mTrial); //

	//4) Sélectionner les meilleurs vecteurs parmi les vecteurs de mutation et les vecteurs de la population actuelle
	processSelection();

	//5) Mettre à jour les statistiques de la génération actuelle
	processStatistics();

	//Incrémente le compteur de génération
	mCurrentGeneration++;

	return true;
}

bool DifferentialEvolution::evolve()
{

	if (!isReady()) {
		return false;
	}

	for (size_t i{}; i < mParameters.getMaxGenerationCount(); ++i ) { //

		if (!evolveOne()) {
			return false;
		}
	}
	return true;
}

/*********************************************************************/

void DifferentialEvolution::setCR(double CR)
{
	mParameters.setCR(CR);
}

void DifferentialEvolution::setF(double F)
{
	mParameters.setF(F);
}
/*********************************************************************/

void DifferentialEvolution::processFitness(DEPopulation& population)
{

	for (size_t i{}; i < population.size(); ++i) { //parcour toutes les solutions de la populations

		// Calcule la valeur de fitness pour la solution presente
		population[i].setObjective(mParameters.getObjFunc(population[i])); //
		population[i].setFitness(mParameters.getFitnessFunc(population[i].getObjective()));
	}
}

void DifferentialEvolution::processMutation()
{
	for (size_t p{}; p < mPopulation.size(); ++p) {//Dans ce code on veut parcourir toutes les solutions de la population

		size_t s1, s2, s3;	//3 solutions distinctes
		mSamplingTool.prepare(mPopulation.size());
		mSamplingTool.select(p, s1, s2, s3);

		mMutant[p] = mPopulation[s1] + (mPopulation[s2] - mPopulation[s3]) * mParameters.getF();
	}
}

/*******************************************************A TERMINER*****************************************************************/
void DifferentialEvolution::processCrossover()
{

	for (size_t p{}; p < mPopulation.size(); ++p) {	//parcours toutes les populations

		size_t R = randomize();	//genere valeur aleatoire a R

		for(size_t i{}; i < mPopulation[p].size(); ++i) {	//on parcours les solution de la population courante

			if(i==R || randomize() < mParameters.getCR()) {

				mTrial[p] = mMutant[p];
			}
			else {
				mTrial[p] = mPopulation[p];
			}
		}
	}
}

void DifferentialEvolution::processSelection()
{
	for (size_t p = 0; p < mPopulation.size(); ++p) {		//parcours toutes les solution de la population courante

		if (mTrial[p].getFitness() >= mPopulation[p].getFitness()) { //compare chaque solution fitness de mTrial a celui de mPopulation
			mPopulation[p] = mTrial[p];
		}
	}
}

void DifferentialEvolution::processStatistics()
{
	DESolution sol{};
	std::vector<double> val{};

	for (size_t p{}; p < mPopulation.size(); ++p) {	//parcourir chacune des populations de la generation courante

		for (size_t i = 0; i < mPopulation[p].size(); ++i) { //le i va nous permettre de parcourir chaque solutions de cette population

			if (val[0] < mPopulation[p].getData()[i]) { //

				val[0] = mPopulation[p].getData()[i]; //on garde une solution specifique i de la population p
				sol.setData(val); //une fois l'analyse de toute les populations de la generation courante, on envoie la meilleur a mStatistics
			}	
		}
	}
	mStatistics.add(sol);
}

size_t DifferentialEvolution::randomize() const
{
	std::default_random_engine generator; //
	//fonction de densite
	std::uniform_int_distribution<size_t> distribution(0,mPopulation.size());
	return distribution(generator);
}