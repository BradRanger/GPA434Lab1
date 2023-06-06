#include "FactoryProductionSolver.h"

FactoryProductionSolver::FactoryProductionSolver()

{
}

FactoryProductionSolver::~FactoryProductionSolver()
{
}
void FactoryProductionSolver::solve(size_t scenario, size_t availableResource)
{
	mDEEngine.reset();
	mDEEngine.isReady();




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

