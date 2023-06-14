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
	
	std::vector<double> mData; //Ce vecteur représente les données d'une solution dans un espace à n dimensions.
	double mObjective; //le résultat du calcul de la fonction objective
	double mFitness; //le résultat du calcul de « fitness »
	  
public:
	DESolution();
	DESolution(const std::vector<double>& size, double objective, double fitness); //avec le deuxieme constructeur nous pouvons creer des nouvelles instances pour mData,mObjective et mFitness
	
	~DESolution();

	//accesseurs
	std::vector<double>& getData(); //pas de const puisque on veut acceder aux mutateurs
	double getObjective() const; 
	double getFitness() const;	
	

	//mutateur
	void setData(const std::vector<double>& data);	
	void setObjective(double objective);
	void setFitness(double fitness);
	
	size_t size() const; //retourne le nombre de paramètres, soit la taille du problème
	void setup(DESolutionBounds const & solutionBounds); //dimensionne le vecteur de données à la dimensionnalité du problème //pointe a l<address de notre vecteur intervalle
	void randomize(DESolutionBounds const & solutionBounds); //assigne à chacune des données du vecteur une valeur générée aléatoirement par chacune des intervalles de solutionBounds

	

	/*********************section operateur*********************************/ 

	bool operator==(DESolution const& rhs);
	bool operator!=(DESolution const& rhs);

	DESolution operator+(DESolution rhs) const;	//addition entre deux objets
	DESolution operator-(DESolution rhs) const;	//soustraction entre deux objets

	DESolution operator-() const;	//operateur pour changement de signe d'un objet

	DESolution operator*(double rhs) const;	//multiplication entre un objet DESolution et un scalaire 
	DESolution operator/(double rhs) const;	//division entre un objet DESolution et un scalaire

	DESolution& operator+=(DESolution const& rhs); //addition composée (+=) entre deux objets
	DESolution& operator-=(DESolution const& rhs); //soustraction composée (-=) entre deux objets
	DESolution& operator*=(double rhs);			   //Multiplication composée (*=) par un scalaire double
	DESolution& operator/=(double rhs);			   //division composée (/=) par un scalaire double


};

#endif