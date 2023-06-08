#pragma once
#ifndef DIFFERENTIAL_EVOLUTION_H
#define DIFFERENTIAL_EVOLUTION_H
#include "DEStatistics.h"
#include "ThreeSamplesWithOneExclusion.h"
#include "DEParameters.h"
#include "DEPopulation.h"
#include <vector>

class DifferentialEvolution{

private:

	DEParameters mParameters;		//
	DEPopulation mPopulation;	// vecteur x
	DEPopulation mMutant;		// vecteur m
	DEPopulation mTrial;		// vecteur t
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