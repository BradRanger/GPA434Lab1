#pragma once
#ifndef DESOLUTIONBOUNDS_H
#define DESOLUTIONBOUNDS_H
#include "interval.h"
#include <vector>

class DESolutionBounds {

private:

	std::vector<Interval> mSolutionBounds; // represente tous les intervalles

public:

	DESolutionBounds();
	~DESolutionBounds();

	std::vector<Interval> solutionBounds() const; 
	size_t size() const; //retourne le nombre d'intervalles

	
};



#endif

