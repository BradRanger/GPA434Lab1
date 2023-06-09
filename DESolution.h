#pragma once
#ifndef DESOLUTION_H
#define DESOLUTION_H
#include "DESolutionBounds.h"
//#include "iostream"
//#include <stdlib.h>
#include <random>
#include <vector>


class DESolution {
private:
	
	std::vector<double> mData; //Ce vecteur repr�sente les donn�es d'une solution dans un espace � n dimensions.
	double mObjective; //le r�sultat du calcul de la fonction objective
	double mFitness; //le r�sultat du calcul de � fitness �
	  

public:
	DESolution();
	DESolution(const std::vector<double>& size, double objective, double fitness); //avec le deuxieme constructeur nous pouvons creer des nouvelles instances pour mData,mObjective et mFitness
	//old: DESolution(double size, double objective, double fitness);
	~DESolution();

	//accesseurs
	const std::vector<double>& getData() const; //old: std::vector<double> Data()
	double getObjective() const; //old: double objective()
	double getFitness() const;	//old: double fitness()
	
	//mutateur
	void setData(const std::vector<double>& data);	//old: void setData();
	void setObjective(double objective);
	void setFitness(double fitness);
	



	size_t size() const; //retourne le nombre de param�tres, soit la taille du probl�me
	void setup(DESolutionBounds const & solutionBounds); //dimensionne le vecteur de donn�es � la dimensionnalit� du probl�me //pointe a l<address de notre vecteur intervalle

	//assigne � chacune des donn�es du vecteur une valeur g�n�r�e al�atoirement par chacune des intervalles de solutionBounds
	void randomize(DESolutionBounds const & solutionBounds);





	/*********************section operateur*********************************/

	bool operator==(DESolution const& rhs);
	bool operator!=(DESolution const& rhs);

	DESolution operator+(DESolution rhs) const;	//addition entre deux objets
	DESolution operator-(DESolution rhs) const;	//soustraction entre deux objets

	DESolution operator-() const;	//operateur pour changement de signe d'un objet


	DESolution operator*(double rhs) const;	//multiplication entre un objet DESolution et un scalaire 
	DESolution operator/(double rhs) const;	//division entre un objet DESolution et un scalaire





	DESolution& operator+=(DESolution const& rhs) ;
	DESolution& operator-=(DESolution const& rhs) ;
	DESolution& operator*=(double rhs) ;
	DESolution& operator/=(double rhs) ;
};

#endif