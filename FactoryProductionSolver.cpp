#include "FactoryProductionSolver.h"

FactoryProductionSolver::FactoryProductionSolver()

{
}

FactoryProductionSolver::~FactoryProductionSolver()
{
}
DifferentialEvolution FactoryProductionSolver::getmDEEngine() const
{
	return mDEEngine;
}
void FactoryProductionSolver::solve(size_t scenario, size_t availableResource)
{
	mDEEngine.reset();
	mDEEngine.isReady();

	size_t n{};

	mDEEngine.evolve();
	mDEEngine.evolveOne();
}

std::string FactoryProductionSolver::problemPresentation()
{
	return "bob";
}

std::string FactoryProductionSolver::solutionPresentation()
{
	return "bob";
}

