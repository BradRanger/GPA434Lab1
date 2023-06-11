#include "DEStatistics.h"

DEStatistics::DEStatistics()
	:mStatistics{}
{
}

DEStatistics::~DEStatistics()
{
}

void DEStatistics::add(DESolution& solution)
{
	mStatistics.push_back(solution);	//
}

void DEStatistics::reset()
{
	mStatistics.clear();	//vide le vecteur
}

bool DEStatistics::isEmpty() const
{
	return mStatistics.empty();	//retourne true si mStatistics est vide
}
