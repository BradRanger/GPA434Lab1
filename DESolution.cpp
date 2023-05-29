#include "DESolution.h"

DESolution::DESolution()
    :mData{}
    ,mFitness{}
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
    
    mData.resize(solutionBounds.size());    //

                // i est passe en reference //for range loop


        randomize(solutionBounds);

    
    
}

void DESolution::randomize(DESolutionBounds const & solutionBounds)
{

    int i{ 0 };


    if(solutionBounds.solutionBounds().size()!=0 && 
       solutionBounds.solutionBounds().size() == mData.size()){

        //interaction with for range loop and vector

        for (Interval &interval : solutionBounds.solutionBounds()){

        
            mData[i] = interval.randomize();
            ++i;
        }

    }

}
