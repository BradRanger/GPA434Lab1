#pragma once
#ifndef DESOLUTION_H
#define DESOLUTION_H
#include "interval.h"
#include <vector>
#include "DESolutionBounds.h"

class DESolution {

	DESolution();
	~DESolution();

	std::vector<double> mData; //représente le vecteur de données
	double mObjective; //le résultat du calcul de la fonction objective
	double mFitness; //le résultat du calcule de « fitness »
	size_t size() const; //retourne le nombre de paramètres, soit la taille du problème
	void setup(DESolutionBounds const & solutionBounds); //dimensionne le vecteur de données à la dimensionnalité du problème
	
	//assigne à
	//chacune des données du vecteur une valeur générée aléatoirement par chacune des intervalles de
	//solutionBounds
	void randomize(DESolutionBounds const & solutionBounds);
};


#endif