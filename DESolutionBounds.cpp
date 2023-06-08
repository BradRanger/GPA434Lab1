#include "DESolutionBounds.h"


DESolutionBounds::DESolutionBounds()
	//initialise par defaut
	:mSolutionBounds(1)	
{
}


DESolutionBounds::~DESolutionBounds()

{
}

std::vector<Interval> DESolutionBounds::solutionBounds() const //vecteur publique
{
	return mSolutionBounds;
}

size_t DESolutionBounds::size() const
{
	return mSolutionBounds.size();
}
