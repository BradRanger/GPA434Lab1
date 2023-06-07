#include "DEPopulation.h"



DEPopulation::DEPopulation()
	:mSolutions()
{
}

DESolution& DEPopulation::operator[](size_t index)
{
	return mSolutions[index];
}

//DESolution& const DEPopulation::operator[](size_t index)
//{
//	return mSolutions[index];
//}


DEPopulation::~DEPopulation()
{
}

size_t DEPopulation::size() const
{
	return size_t();
}




void DEPopulation::setup(size_t populationSize, DESolutionBounds const & solutionBounds)
{
	mSolutions.resize(populationSize);
	for (int i{}; mSolutions.size();) { // mettre tout a 0
		mSolutions[i].setup(solutionBounds);
	}

	randomize(solutionBounds);

}




void DEPopulation::randomize(DESolutionBounds const& solutionBounds)
{
	for (int i{}; mSolutions.size();) {
		mSolutions[i].randomize(solutionBounds);
	}



}
