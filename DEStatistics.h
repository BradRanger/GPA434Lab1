#pragma once
#ifndef DESTATISTICS_H
#define DESTATISTICS_H
#include "DESolution.h"
#include <vector>

/*
Cette classe est un conteneur d�informations. Elle contient un vecteur de DESolution de la taille du
nombre de g�n�rations en cours o� est stock�e la meilleure solution de chaque g�n�ration. C�est l�historique
d��volution
*/
class DEStatistics {

private:

	std::vector<DESolution> mStatistics;
	
public:

	DEStatistics();
	~DEStatistics();

	//accesseurs
	std::vector<DESolution> getStatistics();

	void add(DESolution& solution);
	void reset();
	bool isEmpty() const;
	DESolution& operator[](size_t index);
};

#endif