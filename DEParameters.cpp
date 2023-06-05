#include "DEParameters.h"



DEParameters::DEParameters()
: mSolutionBounds{DESolutionBounds::DESolutionBounds()}
, mPopulationSize{100}
, mF{1}		//0 ≤ 𝐹 ≤ 2  == augmente la chance d'avoir un grand ecart entre les mutants choisis
, mCR{0.2}		//0 ≤ 𝐶𝑅 ≤ 1 == pourcentage de pogner un mutant
, mMaxGenerationCount{100}

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
