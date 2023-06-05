#include "DESolution.h"

DESolution::DESolution()
    :mData{2}
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

bool DESolution::operator==(DESolution const& rhs)
{
    return mData==rhs.mData;
}

bool DESolution::operator!=(DESolution const& rhs)
{
    return !(mData == rhs.mData);
}

DESolution DESolution::operator+(DESolution rhs) const
{
    rhs.mData[0] += mData[0];
    rhs.mData[1] += mData[1];
    return rhs;
}

DESolution DESolution::operator-(DESolution rhs) const
{
    rhs.mData[0] = mData[0]- rhs.mData[0];
    rhs.mData[1] = mData[1]- rhs.mData[1];
    return rhs;

}

//DESolution DESolution::operator-() const
//{
//}

DESolution DESolution::operator*(double rhs) const
{
    return DESolution();
}

DESolution DESolution::operator/(double rhs) const
{
    return DESolution();
}

//DESolution& DESolution::operator+=(DESolution const& rhs)
//{
//    // TODO: insert return statement here
//}
//
//DESolution& DESolution::operator-=(DESolution const& rhs)
//{
//    // TODO: insert return statement here
//}
//
//DESolution& DESolution::operator*=(double rhs)
//{
//    // TODO: insert return statement here
//}
//
//DESolution& DESolution::operator/=(double rhs)
//{
//    // TODO: insert return statement here
//}
