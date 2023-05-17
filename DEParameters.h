#pragma once
#ifndef DEPARAMATERS_H
#define DEPARAMATERS_H


class DEParameters {

	size_t mPopulationSize;
	double mF;
	double mCR;
	double mMaxGenerationCount;

	DEParameters();
	~DEParameters();
	de_objective_function_t_mObjFunc();
	de_fitness_function_t_mFitnessFunc();



};



#endif