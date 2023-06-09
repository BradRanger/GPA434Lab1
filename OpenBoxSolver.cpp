#include "OpenBoxSolver.h"

void OpenBoxSolver::solve(size_t width, size_t height)
{

	size_t x{ 1 };
	size_t volume{ (width - (2 * x) * height - (2 * x))*x };


	mDEEngine.evolve();
	mDEEngine.evolveOne();
	mDEEngine.isReady();
}


std::string OpenBoxSolver::problemPresentation()
{
	return "According to a quick google search, the open box problem...";
}

std::string OpenBoxSolver::solutionPresentation()
{
	return std::string();
}
