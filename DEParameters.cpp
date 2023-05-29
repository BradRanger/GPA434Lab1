#include "DEParameters.h"



DEParameters::DEParameters()
: mSolutionBounds{DESolutionBounds::DESolutionBounds()}
, mPopulationSize{}
, mF{}
, mCR{}
, mMaxGenerationCount{}

{
	
}



DEParameters::~DEParameters()
{
}

void DEParameters::de_objective_function_t_mObjFunc()
{
}

void DEParameters::de_fitness_function_t_mFitnessFunc()
{
}

bool DEParameters::isReady(bool a)
{
	return false;
}

void DEParameters::reset()
{
}

void DEParameters::setPopulationSize(size_t populationSize)
{
	mPopulationSize = populationSize;
}

size_t DEParameters::getPopulationSize()
{
	return mPopulationSize;
}

void DEParameters::setF(double MF)
{
	mF = MF;
}

double DEParameters::getF()
{
	return mF;
}

void DEParameters::setCR(double CR)
{
	mCR = CR;
}

double DEParameters::getCR()
{
	return mCR;
}

void DEParameters::setMaxGenerationCount(double maxGenCount)
{
	mMaxGenerationCount = maxGenCount;
}

double DEParameters::getMaxGenerationCount()
{
	return mMaxGenerationCount;
}
