#pragma once
#ifndef PeaksSolver_h
#define PeaksSolver_h
#define _USE_MATH_DEFINES

#include "DifferentialEvolution.h"
#include <cmath>
#include <vector>

class PeaksSolver {
	DifferentialEvolution mDEEngine;

public:

	DifferentialEvolution getmDEEngine() const;
	PeaksSolver();
	~PeaksSolver();
	void solve(size_t populationSize, size_t generationCount, size_t realPrecision);
	std::vector<std::string> problemPresentation();
	std::string solutionPresentation();


};















#endif // PeaksSolver_h
