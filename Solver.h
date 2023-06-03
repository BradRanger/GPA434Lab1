#pragma once

#include <functional>

class Solver
{
public:
	Solver();

	//float (*objectiveFunction)(float);
	std::function<float(float)> objectiveFunction;

	float process();
};

