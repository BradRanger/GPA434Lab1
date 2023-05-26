#pragma once
#ifndef DEPARAMATERS_H
#define DEPARAMATERS_H


#include "DESolutionBounds.h"
#include "DESolution.h"
#include "functionDeclaration.h"
// prend en reference une reference constance de DESolution

using de_objective_function_t = double(*)(DESolution const& Solution);
using de_fitness_function_t = double(*)(double);

class DEParameters {

	size_t mPopulationSize;
	double mF;
	double mMaxGenerationCount;

	DEParameters();
	~DEParameters();
	void de_objective_function_t_mObjFunc();
	void de_fitness_function_t_mFitnessFunc();

	de_objective_function_t mObjFunct{ nullptr };
	de_fitness_function_t mObjFunct{ nullptr };


};



#endif