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

	//Verifier que les parametres necessaires ont ete definis
	if (mParameters.getPopulationSize() == 0 || mParameters.getMaxGenerationCount()) {

		
		return false;
	}

	
	// Vérifiez que mPopulation, mMutant et mTrial ont la bonne taille
	if (mPopulation.size() != mParameters.getPopulationSize() || mMutant.size() != mParameters.getPopulationSize() || mTrial.size() != mParameters.getPopulationSize()) {

		return false;
	}

	


	//Verifier que les bornes de la solution ont ete definies
	//Verifier que les fonctions objectives et fitness ont ete definies

	//si tous les test ont ete passes, retourner true
	return true;
}

void DifferentialEvolution::setup(DEParameters const& parameters)
{
	
	mSamplingTool.prepare(mParameters.getPopulationSize());

	mPopulation.setup(mParameters.getPopulationSize(), mParameters);
	mTrial.setup(mParameters.getPopulationSize(), mParameters);
	mMutant.setup(mParameters.getPopulationSize(), mParameters);
	
}  

void DifferentialEvolution::reset()
{
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
