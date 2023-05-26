#include "DESolution.h"

DESolution::DESolution()
    :mFitness{}
    ,mObjective{}
{
}

DESolution::~DESolution()
{
}

size_t DESolution::size() const
{
    return size_t();
}

void DESolution::setup(DESolutionBounds const& solutionBounds)
{
    mData.resize(solutionBounds.size());

    for (double &data : mData) {// i est passe en reference //for range loop
        
        data = 0;
    }
}

void DESolution::randomize(DESolutionBounds const& solutionBounds)
{
}
