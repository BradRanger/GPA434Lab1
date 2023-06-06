#pragma once
#ifndef FactoryProductionSolver_H
#define FactoryProductionSolver_H
#include "DifferentialEvolution.h"
#include <string>

class FactoryProductionSolver {

	DifferentialEvolution mDEEngine;

public:

	FactoryProductionSolver();
	~FactoryProductionSolver();

	void solve(size_t scenario, size_t availableResource);
	std::string problemPresentation();
	std::string solutionPresentation();
};













#endif // FactoryProductionSolver_H
