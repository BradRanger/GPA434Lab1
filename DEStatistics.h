#pragma once
#ifndef DESTATISTICS_H
#define DESTATISTICS_H
#include "DESolution.h"
#include <vector>

class DEStatistics {

	std::vector<DESolution> mStatistics;

public:

	DEStatistics();
	~DEStatistics();
	void add(DESolution& solution);
	void reset();

	bool isEmpty() const;
	

};

#endif