#pragma once
#ifndef DESOLUTION_H
#define DESOLUTION_H
#include "interval.h"
#include <vector>
#include "DESolutionBounds.h"
#include "iostream"
#include <stdlib.h>



class DESolution {

private:

	std::vector<double> mData; //repr�sente le vecteur de donn�es
	double mObjective; //le r�sultat du calcul de la fonction objective
	double mFitness; //le r�sultat du calcule de � fitness �


public:
	DESolution();
	~DESolution();

	size_t size() const; //retourne le nombre de param�tres, soit la taille du probl�me
	void setup(DESolutionBounds const & solutionBounds); //dimensionne le vecteur de donn�es � la dimensionnalit� du probl�me //pointe a l<address de notre vecteur intervalle
	
	//assigne �
	//chacune des donn�es du vecteur une valeur g�n�r�e al�atoirement par chacune des intervalles de
	//solutionBounds

	void randomize(DESolutionBounds const & solutionBounds);
};


#endif