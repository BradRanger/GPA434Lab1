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
	//quand tu ne surcharge pas un operateur =, tout est copier
	DEParameters mParameters;	//
	DEPopulation mPopulation;	// vecteur x
	DEPopulation mMutant;		// vecteur m
	DEPopulation mTrial;		// vecteur t
	size_t mCurrentGeneration;
	DEStatistics mStatistics;					
	ThreeSamplesWithOneExclusion mSamplingTool; 

	

	void processFitness(DEPopulation& population);
	void processMutation();
	void processCrossover();
	void processSelection();
	void processStatistics();


public:

	DifferentialEvolution();
	~DifferentialEvolution();

	//accesseur
	DEParameters getParameters() const;
	size_t getCurrentGeneration() const;


	bool isReady() const;
	void setup(DEParameters const& parameters);
	void reset();
	bool evolveOne();
	bool evolve();


	void setCR(double CR);
	void setF(double F);

	size_t DifferentialEvolution::randomize() const;
};

#endif