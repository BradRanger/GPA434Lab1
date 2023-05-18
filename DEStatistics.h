#pragma once
#ifndef DESTATISTICS_H
#define DESTATISTICS_H
#include "interval.h"
#include <vector>

class DEStatistics {
	
	DEStatistics();
	~DEStatistics();
	std::vector<DESolution> mStatistics;
	void add(DESolution& const solution);
	void reset();
}

#endif