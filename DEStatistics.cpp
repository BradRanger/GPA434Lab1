#include "DEStatistics.h"

DEStatistics::DEStatistics()
	:mStatistics{}
{
}

DEStatistics::~DEStatistics()
{
}

std::vector<DESolution>& DEStatistics::getStatistics()
{
	return mStatistics;
}


void DEStatistics::add(DESolution& solution)
{
	/*
	DifferentialEvolution evo;
	mStatistics.resize(evo.getCurrentGeneration());
	mStatistics[evo.getCurrentGeneration()].setData(solution.getData());
	*/

	mStatistics.push_back(solution);

}


void DEStatistics::reset()
{
	mStatistics.clear();	//vide le vecteur
}

bool DEStatistics::isEmpty() const
{
	return mStatistics.empty();	//retourne true si mStatistics est vide
}

DESolution& DEStatistics::operator[](size_t index)
{
	return mStatistics[index];
}



