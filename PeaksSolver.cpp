#include "PeaksSolver.h"

PeaksSolver::PeaksSolver()
{
}

PeaksSolver::~PeaksSolver()
{
}

void PeaksSolver::solve(size_t populationSize, size_t generationCount, size_t realPrecision)
{
	mDEEngine.reset();
	mDEEngine.isReady();
	size_t x{}, y{};

	{
		size_t sol((3.0 * pow(1.0 - x, 2.0) * pow(M_E, -(pow(x, 2.0) + pow(y + 1.0, 2.0))))
			- 10.0 * (x / 5.0 - pow(x, 3.0) - pow(y, 5.0)) * pow(M_E, -(pow(x, 2.0) + pow(y, 2.0))
				- 1.0 / 3.0 * pow(M_E, -(pow((x + 1.0), 2.0) + pow(y, 2.0)))));
	}

	mDEEngine.evolve();
	mDEEngine.evolveOne();

}

std::string PeaksSolver::problemPresentation()
{
	return std::string();
}

std::string PeaksSolver::solutionPresentation()
{
	return std::string();
}
