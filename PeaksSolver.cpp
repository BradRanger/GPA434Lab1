#include "PeaksSolver.h"

PeaksSolver::PeaksSolver()
{
}

PeaksSolver::~PeaksSolver()
{
}

DifferentialEvolution PeaksSolver::getmDEEngine() const
{
	return mDEEngine;
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

std::vector<std::string> PeaksSolver::problemPresentation()
{
	std::vector<std::string> problemPres;
	problemPres.resize(5);

	problemPres[0] = "La celebre fonction <Three Peaks> consiste en une relation entre deux variables qui ";
	problemPres[1] = "cree une topographie a 3 sommets et 2 creus. L'evaluation des valeurs minimales ";
	problemPres[2] = "et maximales (sommets et creus) dans ce probleme peut causer probleme, car il y a risque";
	problemPres[3] = "de tomber dans des minimums et maximums locaux. Regardons si notre implementation ";
	problemPres[4] = "nous permet de trouver les solutions.";
	return problemPres;
}

std::vector<std::string> PeaksSolver::solutionPresentation()
{
	std::vector<std::string> solutionPres;
	solutionPres.resize(5);
	solutionPres[0] = "La celebre fonction <Three Peaks> consiste en une relation entre deux variables qui ";
	solutionPres[1] = "cree une topographie a 3 sommets et 2 creus. L'evaluation des valeurs minimales ";
	solutionPres[2] = "et maximales (sommets et creus) dans ce probleme peut causer probleme, car il y a risque";
	solutionPres[3] = "de tomber dans des minimums et maximums locaux. Regardons si notre implementation ";
	solutionPres[4] = "nous permet de trouver les solutions.";

	return solutionPres;
}

double peaksObjFunc(const DESolution& solution) {

	return 1.0;
}
double peaksFitFunc(double db) {

	return 1.0;
}
