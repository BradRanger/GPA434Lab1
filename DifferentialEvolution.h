#pragma once
#ifndef DIFFERENTIAL_EVOLUTION_H
#define DIFFERENTIAL_EVOLUTION_H
#include "interval.h"
#include <vector>
#include "DEParameters.h"
#include "DEPopulation.h"

class DifferentialEvolution{

	DifferentialEvolution();
	~DifferentialEvolution();
	bool isReady() const;
	void setup(DEParameters const& paremeters);
	void reset();
	void evolveOne();
	void evolve();
	void processFitness(DEPopulation& population);
	void ProcessMutation();
	void ProcessCrossover();
	void ProcessSelection();
	void ProcessStatistics();
};

#endif