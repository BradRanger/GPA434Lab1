#pragma once
#ifndef DESOLUTION_H
#define DESOLUTION_H
#include "interval.h"
#include <vector>
#include "DESolutionBounds.h"
#include "iostream"
#include <stdlib.h>
#include <random>


class DESolution {

private:
	
	std::vector<double> mData; //représente le vecteur de données
	double mObjective; //le résultat du calcul de la fonction objective
	double mFitness; //le résultat du calcul de « fitness »


public:
	DESolution();
	DESolution(double size,double objective,double fitness);
	~DESolution();

	std::vector<double> data();
	double objective();
	double fitness();

	void setData();
	void setObjective();
	void setFitness();
	size_t size() const; //retourne le nombre de paramètres, soit la taille du problème
	void setup(DESolutionBounds const & solutionBounds); //dimensionne le vecteur de données à la dimensionnalité du problème //pointe a l<address de notre vecteur intervalle
	
	//assigne à
	//chacune des données du vecteur une valeur générée aléatoirement par chacune des intervalles de
	//solutionBounds

	void randomize(DESolutionBounds const & solutionBounds);

	bool operator==(DESolution const& rhs);
	bool operator!=(DESolution const& rhs);

	DESolution operator+(DESolution rhs) const;
	DESolution operator-(DESolution rhs) const;
	//DESolution operator-() const;


	DESolution operator*(double rhs) const;
	DESolution operator/(double rhs) const;

	//DESolution& operator+=(DESolution const& rhs) ;
	//DESolution& operator-=(DESolution const& rhs) ;
	//DESolution& operator*=(double rhs) ;
	//DESolution& operator/=(double rhs) ;
};


#endif