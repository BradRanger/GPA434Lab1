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
	if (mParameters.getPopulationSize() == 0 || mParameters.getMaxGenerationCount() == 0 || mParameters.getF() <= 0 || mParameters.getCR() < 0 || mParameters.getCR() > 1) {
		return false;
	}

	// V�rifie que mPopulation, mMutant et mTrial ont la bonne taille
	if (mPopulation.size() != mParameters.getPopulationSize() || mMutant.size() != mParameters.getPopulationSize() || mTrial.size() != mParameters.getPopulationSize()) {
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
	mPopulation.setup(mParameters.getPopulationSize(), mParameters.getSolutionBounds());	//corriger mParameters, c'est un mSolutionBounds 
	mTrial.setup(mParameters.getPopulationSize(), mParameters.getSolutionBounds());
	mMutant.setup(mParameters.getPopulationSize(), mParameters.getSolutionBounds());
}  

void DifferentialEvolution::reset()
{
	// R�initialisez la population de solutions
	mPopulation.setup(mParameters.getPopulationSize(), mParameters.getSolutionBounds());
	mPopulation.randomize(mParameters.getSolutionBounds());

	// R�initialisez la population de solutions
	mMutant.setup(mParameters.getPopulationSize(), mParameters.getSolutionBounds());
	mMutant.randomize(mParameters.getSolutionBounds());

	// R�initialisez la population de solutions
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
	return false;
}

bool DifferentialEvolution::evolve()
{
	return false;
}


void DifferentialEvolution::processFitness(DEPopulation& population)
{
}

void DifferentialEvolution::ProcessMutation()
{
}

void DifferentialEvolution::ProcessCrossover()
{
}

void DifferentialEvolution::ProcessSelection()
{
}

void DifferentialEvolution::ProcessStatistics()
{
}
