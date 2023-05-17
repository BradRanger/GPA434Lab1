#pragma once
#ifndef POPULATION_H
#define POPULATION_H
#include "interval.h"
#include <vector>

class DEPopulation {

	DEPopulation();
	~DEPopulation();
	std::vector<DESolution> mSolutions;
	size_t size() const;
	void setup(size_t populationSize, DESolutionBounds const& solutionBounds);
	void randomize(DESolutionBounds const& solutionBounds);
}

#endif