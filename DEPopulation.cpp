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
	mSolutions.resize(populationSize);	//mSolutions c'est notre x,la population en cours. notre vecteur prend la taille de populationsize


	for (int i{}; mSolutions.size();){ //initialisation du vecteur

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
