#include "DESolutionBounds.h"




DESolutionBounds::DESolutionBounds()
	:mSolutionBounds(20)	//creer 3 intervalles par defaut
{
	for (int i{}; i < mSolutionBounds.size(); ++i) {

		mSolutionBounds[i].set(10 * (i + 1), 20 * (i + 1));	
	}
}


DESolutionBounds::~DESolutionBounds()
{
}

std::vector<Interval> DESolutionBounds::solutionBounds() const
{
	return mSolutionBounds;
}

size_t DESolutionBounds::size() const
{
	return mSolutionBounds.size();
}
