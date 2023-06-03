#include "Solver.h"

Solver::Solver()
	: objectiveFunction{}
{
}

float Solver::process()
{
	if (objectiveFunction != nullptr) {
		return objectiveFunction(3.1415f);
	} else {
		return 0.0f;
	}
}
