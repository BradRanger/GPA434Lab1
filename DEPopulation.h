#pragma once
#ifndef POPULATION_H
#define POPULATION_H
#include <vector>
#include "DESolution.h"
#include "DESolutionBounds.h"

class DEPopulation { // dispatcher sur toutes les solutions

private:

	std::vector<DESolution> mSolutions;

public:

	DEPopulation();
	~DEPopulation();

	//accesseurs
	std::vector<DESolution>& getSolutions();

	//mutateurs
	void setSolutions(const std::vector<DESolution>& solutions);

	size_t size() const;
	void setup(size_t populationSize, DESolutionBounds const& solutionBounds); //passe a travers toutes les solutions et fait setup a travers chacune des solutions
	void randomize(DESolutionBounds const & solutionBounds);

	DESolution& operator[](size_t index);

};

#endif