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
	return true;
}

void DifferentialEvolution::setup(DEParameters const& parameters)
{
	
	mSamplingTool.prepare(mParameters.size());
	mPopulation.setup(mParameters.size(),mParameters);
	mTrial.setup(mParameters.size(), mParameters);
	mMutant.setup(mParameters.size(), mParameters);
	
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
