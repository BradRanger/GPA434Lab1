#include "DESolution.h"

DESolution::DESolution()
    :mData{}
    ,mFitness{}
    ,mObjective{}
{
}

DESolution::DESolution(double size, double objective, double fitness)
{
    setData();
    setObjective(objective);
    setFitness(fitness);

}
DESolution::~DESolution()
{
}

std::vector<double> DESolution::data()
{
    return mData;
}

double DESolution::objective()
{
    return mObjective;
}

double DESolution::fitness()
{
    return mFitness;
}

void DESolution::setData()
{
    //mData = size;
}

void DESolution::setObjective(double objective)
{
    mObjective = objective;

}

void DESolution::setFitness(double fitness)
{
    
    mFitness = fitness;
}




size_t DESolution::size() const
{
    return size_t();
}

void DESolution::setup(DESolutionBounds const& solutionBounds)
{
    
    mData.resize(solutionBounds.size());

    randomize(solutionBounds);

    
    
}

void DESolution::randomize(DESolutionBounds const & solutionBounds)
{



    if(solutionBounds.solutionBounds().size()!=0 && 
       solutionBounds.solutionBounds().size() == mData.size()){

        //interaction with for range loop and vector
        int i{};

        for (Interval const &interval : solutionBounds.solutionBounds()) {

        
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
    // boucle for qui parcoure les n dimensions
    rhs.mData[0] += mData[0];
    rhs.mData[1] += mData[1];
    return rhs;
}

DESolution DESolution::operator-(DESolution rhs) const
{
    // boucle for qui parcoure les n dimensions
    rhs.mData[0] = mData[0]- rhs.mData[0];
    rhs.mData[1] = mData[1]- rhs.mData[1];
    return rhs;

}

DESolution DESolution::operator-() const
{
    DESolution sol;
    sol.mData.resize(mData.size());
    for (int i{ 0 }; i < mData.size(); ++i) {
        sol.mData[i] = -mData[i];
    }
    return sol;
}

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
