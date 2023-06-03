#include "Population.h"

void Population::resize(size_t size, Vect2D const& defaultValue)
{
	mPopulation.resize(size);
	resetAllValues(defaultValue);
}

void Population::resetAllValues(Vect2D const& value)
{
	for (Vect2D & iValue : mPopulation) {
		iValue = value;
	}
}

void Population::addValue(double x, double y)
{
	mPopulation.push_back(Vect2D(x, y));
}

Vect2D& Population::operator[](size_t index)
{
	return mPopulation[index];
}

Vect2D const Population::operator[](size_t index) const
{
	return mPopulation[index];
}