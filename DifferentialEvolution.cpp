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

	//Verifie que les parametres necessaires ont ete definis
	if (mParameters.getPopulationSize() == 0 || 
		mParameters.getMaxGenerationCount() == 0 || 
		mParameters.getF() <= 0 || 
		mParameters.getCR() < 0 || 
		mParameters.getCR() > 1) {
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
	for (size_t i{}; i < population.size(); ++i) {

		DESolution& solution = population[i];

		// Calcule la valeur de fitness pour la solution presente
		double fitness = mParameters.getObjFunc(solution);

		// met la valeur actuel de fitness dans l'objet solution
		solution.setFitness(fitness);
	}
}

void DifferentialEvolution::processMutation()
{
	for (size_t i{}; i < mPopulation.size(); ++i) {

		size_t s1, s2, s3;
		
		mSamplingTool.select(i, s1, s2, s3);

		for (size_t i{}; i < mPopulation[i].size(); ++i) {
			//double valeurMutante = mPopulation[s1][i] + mParameters.getF() * (mPopulation[s2][i] - mPopulation[s3][i]);

		}
	}
}

void DifferentialEvolution::processCrossover()
{
}

void DifferentialEvolution::processSelection()
{
}

void DifferentialEvolution::processStatistics()
{
}
