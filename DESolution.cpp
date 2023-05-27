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
    
    mData.resize(solutionBounds.size());    //

    for (double &data : mData) {            // i est passe en reference //for range loop


        randomize(solutionBounds);

       // data = solutionBounds;
    }
    
}

void DESolution::randomize(DESolutionBounds const & solutionBounds)
{
   //DESolutionBounds i;
   // 

   //i = solutionBounds;
   //std::cout << i.size();       //test pour verifier qu<on extrait le bon data de l'intervalle
   //
   //i.solutionBounds();




   std::vector<Interval> test;  //


   test = solutionBounds.solutionBounds();  //une copie du vecteur solutionBounds

   std::cout<< test[0].lower();  

   

}
