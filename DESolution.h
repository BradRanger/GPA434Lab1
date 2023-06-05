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
	
	std::vector<double> mData; //repr�sente le vecteur de donn�es
	double mObjective; //le r�sultat du calcul de la fonction objective
	double mFitness; //le r�sultat du calcul de � fitness �


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
	size_t size() const; //retourne le nombre de param�tres, soit la taille du probl�me
	void setup(DESolutionBounds const & solutionBounds); //dimensionne le vecteur de donn�es � la dimensionnalit� du probl�me //pointe a l<address de notre vecteur intervalle
	
	//assigne �
	//chacune des donn�es du vecteur une valeur g�n�r�e al�atoirement par chacune des intervalles de
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