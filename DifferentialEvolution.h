#pragma once
#ifndef DIFFERENTIAL_EVOLUTION_H
#define DIFFERENTIAL_EVOLUTION_H
#include "interval.h"
#include "DEStatistics.h"
#include "ThreeSamplesWithOneExclusion.h"
#include <vector>
#include "DEParameters.h"
#include "DEPopulation.h"

class DifferentialEvolution{

	DESolutionBounds mParameters;
	DEPopulation mPopulation;
	DEPopulation mMutant;
	DEPopulation mTrial;
	size_t mCurrentGeneration;
	DEStatistics mStatistics;					
	ThreeSamplesWithOneExclusion mSamplingTool; 

	
	void processFitness(DEPopulation& population);
	void ProcessMutation();
	void ProcessCrossover();
	void ProcessSelection();
	void ProcessStatistics();



public:


	DifferentialEvolution();
	~DifferentialEvolution();

	bool isReady() const;
	void setup(DEParameters const& parameters);
	void reset();
	bool evolveOne();
	bool evolve();

};

#endif