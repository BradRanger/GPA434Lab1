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
	return false;
}

void DifferentialEvolution::setup(DEParameters const& paremeters)
{
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
