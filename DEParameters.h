#pragma once
#ifndef DEPARAMATERS_H
#define DEPARAMATERS_H


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
	size_t mPopulationSize;		//Taille population P (vecteurs x,m et t)
	double mF;					//constante F
	double mCR;					//valeur constante CR
	double mMaxGenerationCount; //nombre de generations avant d'arreter

	
	mObjFunc;		//a corriger pointeur de fonction
	mFitnessFunc;	//pointeur de fonction

public:

	DEParameters();
	~DEParameters();

	bool isReady(bool a) const;
	void reset();

	void setPopulationSize(size_t populationSize);
	size_t getPopulationSize() const;

	void setF(double CR);
	double getF() const;

	void setCR(double CR);
	double getCR() const;

	void setMaxGenerationCount(double maxGenCount);
	double getMaxGenerationCount() const;

	//fonction constante reference pour le getter
	//accesseur doit etre constant

	

};



#endif