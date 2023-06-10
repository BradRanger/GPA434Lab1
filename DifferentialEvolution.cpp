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

	if (mCurrentGeneration != 0) {
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


	// Réinitialisez la génération actuelle
	mCurrentGeneration = 0;

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

	for (size_t i{}; i < mParameters.getMaxGenerationCount(); ++i ) {

		if (!evolveOne()) {
			return false;
		}
	}
	return true;
}

void DifferentialEvolution::processFitness(DEPopulation& population)
{
	std::vector<DESolution>& solution = population.getSolutions();

	for (size_t i{}; i < solution.size(); ++i) { //parcour toutes les solutions de la populations

		// Calcule la valeur de fitness pour la solution presente
		double fitness = mParameters.getObjFunc(population.getSolutions()[i]);
		
		solution[i].setFitness(fitness);	////vecteur desolution ne peut pas etre const car on veut pouvoir utiliser les fonctions set pour le modifier; ***a modifier 
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

void DifferentialEvolution::processCrossover()
{

	for (size_t p{}; p < mPopulation.size(); ++p) {	//prend la taille de la population

		size_t R = randomize();	//genere valeur aleatoire a R

		for(size_t i{}; i < mPopulation[p].size(); ++i) {	//

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
}

void DifferentialEvolution::processStatistics()
{
}

size_t DifferentialEvolution::randomize() const
{
	std::default_random_engine generator; //
	//fonction de densite
	std::uniform_real_distribution<size_t> distribution(0,mPopulation.size());	//
	return distribution(generator);
}

