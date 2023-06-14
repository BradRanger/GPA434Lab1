#include "DEPopulation.h"


DEPopulation::DEPopulation()
	:mSolutions{}
{
}

DEPopulation::~DEPopulation()
{
}

std::vector<DESolution>& DEPopulation::getSolutions()
{
	return mSolutions;
}

void DEPopulation::setSolutions(const std::vector<DESolution>& solutions)
{
	mSolutions = solutions;
}

size_t DEPopulation::size() const
{
	return mSolutions.size();
}

void DEPopulation::setup(size_t populationSize, DESolutionBounds const & solutionBounds)
{
	mSolutions.resize(populationSize);	//mSolutions c'est notre x,la population en cours. notre vecteur prend la taille de populationsize

	for (size_t i{}; i < mSolutions.size();++i){ //initialisation du vecteur

		mSolutions[i].setup(solutionBounds);
	}

	randomize(solutionBounds);
}

void DEPopulation::randomize(DESolutionBounds const& solutionBounds)
{
	for (size_t i{}; i < mSolutions.size(); ++i) {
		mSolutions[i].randomize(solutionBounds);
	}
}


DESolution& DEPopulation::operator[](size_t index)
{
	return mSolutions[index];
}
