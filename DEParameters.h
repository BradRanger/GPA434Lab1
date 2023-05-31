#pragma once
#ifndef DEPARAMATERS_H
#define DEPARAMATERS_H


#include "DESolutionBounds.h"
#include "DESolution.h"
#include "functionDeclaration.h"

// prend en reference une reference constante de DESolution
//points to the adress of a function that receives a const DESolution reference and the function is expected to return a double 
using de_objective_function_t = double(*)(DESolution const& Solution); //parenthese etoile veut juste dire pointeur de fonction
using de_fitness_function_t = double(*)(double);

class DEParameters {

	DESolutionBounds mSolutionBounds;	//contient structure d'info sur le domaine de chq. param du prob

	size_t mPopulationSize;		//Taille population P (vecteurs x,m et t)
	double mF;					//constante F
	double mCR;					//valeur constante CR
	double mMaxGenerationCount; //nombre de generations avant d'arreter

	DEParameters();
	~DEParameters();
	void de_objective_function_t_mObjFunc();
	void de_fitness_function_t_mFitnessFunc();

public:
	bool isReady(bool a);
	void reset();

	void setPopulationSize(size_t populationSize);
	size_t getPopulationSize();

	void setF(double CR);
	double getF();

	void setCR(double CR);
	double getCR();

	void setMaxGenerationCount(double maxGenCount);
	double getMaxGenerationCount();

};



#endif