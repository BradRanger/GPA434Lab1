#include "DESolutionBounds.h"



//constructeur *********************************** a voir
DESolutionBounds::DESolutionBounds()
	//initialise par defaut
	:mSolutionBounds()	//creer 3 intervalles par defaut
{
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
