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

	// V�rifie que mPopulation, mMutant et mTrial ont la bonne taille
	if (mPopulation.size() != mParameters.getPopulationSize() 
		|| mMutant.size() != mParameters.getPopulationSize() 
		|| mTrial.size() != mParameters.getPopulationSize()) {
		return false;
	}

	if (mCurrentGeneration != 0) {
		return false;
	}

	//v�rifie si le vecteur mStatistics contient des donn�es. si oui, retourne false
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
	// R�initialisez la population de solutions
	mPopulation.setup(mParameters.getPopulationSize(), mParameters.getSolutionBounds());
	mPopulation.randomize(mParameters.getSolutionBounds());

	// R�initialisez la population de mutants
	mMutant.setup(mParameters.getPopulationSize(), mParameters.getSolutionBounds());
	mMutant.randomize(mParameters.getSolutionBounds());

	// R�initialisez la population de trial
	mTrial.setup(mParameters.getPopulationSize(), mParameters.getSolutionBounds());
	mTrial.randomize(mParameters.getSolutionBounds());


	// R�initialisez la g�n�ration actuelle
	mCurrentGeneration = 0;

	// R�initialisez les statistiques
	mStatistics.reset();


	// R�initialisez l'outil d'�chantillonnage
	mSamplingTool = ThreeSamplesWithOneExclusion();

	/*A TESTER POUR VERIFIER QUE TOUT SE REINITILAISE CORRECTEMENT*/
}

bool DifferentialEvolution::evolveOne()
{

	if (!isReady()) {
		return false;
	}

	//1) �valuer la fitness de la population actuelle
	processFitness(mPopulation);

	//2) Effectuer la mutation des vecteurs
	processMutation();

	//3) Effectuer le croisement des vecteurs mutants avec les vecteurs de la population actuelle
	processCrossover();

	//4) S�lectionner les meilleurs vecteurs parmi les vecteurs de mutation et les vecteurs de la population actuelle
	processSelection();

	//5) Mettre � jour les statistiques de la g�n�ration actuelle
	processStatistics();

	//Incr�mente le compteur de g�n�ration
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


		// Calculate the fitness value for the current solution
		//double fitness = mParameters.getFitnessFunc()(solution.getObjective());


		// Set the fitness value in the solution object
		//solution.setFitness(fitness);

	}


}

void DifferentialEvolution::processMutation()
{
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
