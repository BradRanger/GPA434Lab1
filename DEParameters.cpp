#include "DEParameters.h"



DEParameters::DEParameters()
: mSolutionBounds{DESolutionBounds::DESolutionBounds()}
, mPopulationSize{100}
, mF{1}		//0 ≤ 𝐹 ≤ 2  == augmente la chance d'avoir un grand ecart entre les mutants choisis
, mCR{0.2}		//0 ≤ 𝐶𝑅 ≤ 1 == pourcentage de pogner un mutant
, mMaxGenerationCount{100}
, mFitnessFunc(nullptr) // initialise mFitnessFunc
, mObjFunc(nullptr) // initialise mObjFunc
{
	
}


DEParameters::~DEParameters()
{
}

bool DEParameters::isReady() const
{
	//Verifie que les parametres necessaires ont ete definis
	if (getPopulationSize() == 0 ||getF() < 0 || getF() > 2 ||getCR() < 0 ||getCR() > 1 || getMaxGenerationCount() == 0) {
		return false;
	}

	return true;
}

void DEParameters::reset()
{
	mSolutionBounds = DESolutionBounds{}; // Reset solution a sa valeur par defaut
	mPopulationSize = 100; // Reset la popoulation
	mF = 1.0; // Reset la constante F
	mCR = 0.2; // Reset la constante CR
	mMaxGenerationCount = 100; // Reset valeur par defaut

}

void DEParameters::setPopulationSize(size_t populationSize)
{
	mPopulationSize = populationSize;
}

size_t DEParameters::getPopulationSize() const
{
	return mPopulationSize;
}

void DEParameters::setF(double MF)
{
	mF = MF;
}

double DEParameters::getF() const
{
	return mF;
}

void DEParameters::setCR(double CR)
{
	mCR = CR;
}

double DEParameters::getCR() const
{
	return mCR;
}

void DEParameters::setMaxGenerationCount(size_t maxGenCount)
{
	mMaxGenerationCount = maxGenCount;
}

size_t DEParameters::getMaxGenerationCount() const
{
	return mMaxGenerationCount;
}

void DEParameters::setSolutionBounds(DESolutionBounds& solutionBounds)
{
	mSolutionBounds = solutionBounds;
}

DESolutionBounds DEParameters::getSolutionBounds() const
{
	return mSolutionBounds;
}

void DEParameters::setObjFunc(double(*objFunc)(const DESolution&))
{
	mObjFunc = objFunc;
}

double DEParameters::getObjFunc(const DESolution& solution) const
{
	return mObjFunc(solution);
}

void DEParameters::setFitnessFunc(double(*fitnessFunc)(double))
{
	mFitnessFunc = fitnessFunc;
}

double DEParameters::getFitnessFunc(double value) const
{
	return mFitnessFunc(value);
}
