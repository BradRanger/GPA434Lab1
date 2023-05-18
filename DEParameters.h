#pragma once
#ifndef DEPARAMATERS_H
#define DEPARAMATERS_H


class DEParameters {

	size_t mPopulationSize;
	double mF;
	double mMaxGenerationCount;

	DEParameters();
	~DEParameters();
	void de_objective_function_t_mObjFunc();
	void de_fitness_function_t_mFitnessFunc();



};



#endif