#pragma once
#ifndef POPULATION_H
#define POPULATION_H
#include "interval.h"
#include <vector>
#include "DESolution.h"
#include "DESolutionBounds.h"

class DEPopulation {


private:

	std::vector<DESolution> mSolutions;



public:

	DEPopulation();
	~DEPopulation();

	size_t size() const;

	void setup(size_t populationSize, DESolutionBounds const& solutionBounds);
	void randomize(DESolutionBounds const & solutionBounds);

	DESolution& operator[](size_t index);
	//DESolution& const operator[](size_t index);

};

#endif