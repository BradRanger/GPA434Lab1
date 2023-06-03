#pragma once

#include <vector>
#include "Vect2D.h"

class Population
{
public:

	void resize(size_t size, Vect2D const& defaultValue);
	void resetAllValues(Vect2D const& value);
	void addValue(double x, double y);

	Vect2D& operator[](size_t index);
	Vect2D const operator[](size_t index) const;


private:
	std::vector<Vect2D> mPopulation;
};

