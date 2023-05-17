#pragma once
#ifndef DESOLUTION_H
#define DESOLUTION_H
#include "interval.h"
#include <vector>
#include "DESolutionBounds.h"

class DESolution {

	DESolution();
	~DESolution();

	std::vector<double> mData; //repr�sente le vecteur de donn�es
	double mObjective; //le r�sultat du calcul de la fonction objective
	double mFitness; //le r�sultat du calcule de � fitness �
	size_t size() const; //retourne le nombre de param�tres, soit la taille du probl�me
	void setup(DESolutionBounds const & solutionBounds); //dimensionne le vecteur de donn�es � la dimensionnalit� du probl�me
	
	//assigne �
	//chacune des donn�es du vecteur une valeur g�n�r�e al�atoirement par chacune des intervalles de
	//solutionBounds
	void randomize(DESolutionBounds const & solutionBounds);
};


#endif