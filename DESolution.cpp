#include "DESolution.h"

DESolution::DESolution()
    :mData{}
    ,mFitness{}
    ,mObjective{}
{
}

DESolution::DESolution(const std::vector<double>& size, double objective, double fitness)  //a valider
{
    setData(size);
    setObjective(objective);
    setFitness(fitness);
}

DESolution::~DESolution()
{
}

const std::vector<double>& DESolution::getData() const
{
    return mData;
}

double DESolution::getObjective() const
{
    return mObjective;
}

double DESolution::getFitness() const
{
    return mFitness;
}

void DESolution::setData(const std::vector<double>& data)
{
    mData = data;
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
    return mData.size();
}

void DESolution::setup(DESolutionBounds const& solutionBounds)
{
    mData.resize(solutionBounds.size());    // on redimensionne le vecteur avec la taille de donne
    randomize(solutionBounds);
}

void DESolution::randomize(DESolutionBounds const & solutionBounds)
{
    if(solutionBounds.solutionBounds().size()!=0 && solutionBounds.solutionBounds().size() == mData.size()){

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
    for (int i{ 0 }; i < mData.size(); ++i) {
        rhs.mData[i] += mData[i];
    }
    return rhs;
}

DESolution DESolution::operator-(DESolution rhs) const
{
    for (int i{ 0 }; i < mData.size(); ++i) {
        rhs.mData[i] = mData[i] - rhs.mData[i];
    }
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
