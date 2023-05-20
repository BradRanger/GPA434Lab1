#pragma once
#ifndef DESOLUTIONBOUNDS_H
#define DESOLUTIONBOUNDS_H
#include "interval.h"
#include <vector>

//Cette classe représente 𝑙⃗ et 𝑢⃗⃗ . Elle offre tous les services nécessaires à la gestion adéquate des informations
//requises.Ainsi, l’utilisation d’un vecteur d’intervalle permettra à la fois de connaître la dimension du
//problème ainsi que les bornes supérieures et inférieures de chaque paramètre(de chaque dimension).
//std::vector<Interval> mSolutionBounds représente tous les intervalles
//size_t size() const; retourne le nombre d’intervalles, soit la taille du problème
//Pour ce projet, cette classe représente l’un des éléments fondamentaux du système : l’architecture des
//solutions.On y retrouve la dimensionnalité du problème et le domaine pour chaque dimension.
//

class DESolutionBounds {

	std::vector<Interval> mSolutionBounds; // represente tous les intervalles

public:

	DESolutionBounds();
	~DESolutionBounds();

	std::vector<Interval> solutionBounds() const; 
	size_t size() const; //retourne le nombre d'intervalles

	
};



#endif

