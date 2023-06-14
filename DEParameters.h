#pragma once
#ifndef DEPARAMATERS_H
#define DEPARAMATERS_H
#include "DESolution.h"
#include "DESolutionBounds.h"
#include "functionDeclaration.h"

// prend en reference une reference constante de DESolution

//points to the adress of a function that receives a const DESolution reference and the function is expected to return a double 
//permet de definir la facon devaluer tout dependament du probleme

//using de_objective_function_t = double(*)(DESolution const&); //parenthese etoile veut juste dire pointeur de fonction
//using de_fitness_function_t = double(*)(double);

class DEParameters {

private:

	DESolutionBounds mSolutionBounds;	//contient structure d'info sur le domaine de chq. param du prob
	size_t mPopulationSize;				//Taille population P (vecteurs x,m et t)
	double mF;							//constante F
	double mCR;							//valeur constante CR
	size_t mMaxGenerationCount;			//nombre de generations avant d'arreter

	double (*mObjFunc)(const DESolution&);	
	double (*mFitnessFunc)(double);			

public:
	DEParameters();
	~DEParameters();

	bool isReady() const;
	void reset();

	void setPopulationSize(size_t populationSize);
	size_t getPopulationSize() const;

	void setF(double F);
	double getF() const;

	void setCR(double CR);
	double getCR() const;

	void setMaxGenerationCount(size_t maxGenCount);
	size_t getMaxGenerationCount() const;

	//pour pouvoir acceder à mSolutionBounds
	void setSolutionBounds(DESolutionBounds& solutionBounds);		
	DESolutionBounds getSolutionBounds() const;

	void setObjFunc(double (*objFunc)(const DESolution&));
	double getObjFunc(const DESolution& solution) const;

	void setFitnessFunc(double (*fitnessFunc)(double));
	double getFitnessFunc(double value) const;
};



#endif