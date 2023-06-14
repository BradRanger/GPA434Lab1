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

std::vector<double>& DESolution::getData()
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
}

void DESolution::randomize(DESolutionBounds const & solutionBounds)
{
    if(solutionBounds.solutionBounds().size()!=0 && solutionBounds.solutionBounds().size() == mData.size()) {

        for (size_t i{}; i < solutionBounds.solutionBounds().size(); ++i) {    //boucle for pour parcourir les intervalles dans solutionBounds
            
            mData[i] = solutionBounds.solutionBounds()[i].randomize();  //[i] permet d'acceder a l'intervalle voulue pour ensuite generer une valeur aleatoire
        }                                                               //cette valeur est ensuite assigne a la position correspondate dans mData
    }
}

bool DESolution::operator==(DESolution const& rhs)
{
    return mData == rhs.mData && mObjective == rhs.mObjective && mFitness == rhs.mFitness;  //a valider si il faut le faire pour les trois parametres
}

bool DESolution::operator!=(DESolution const& rhs)
{
    return !(*this == rhs); //voir syntaxe du prof
}

DESolution DESolution::operator+(DESolution rhs) const
{
    for (size_t i = 0; i < mData.size(); ++i) {
        rhs.mData[i] += mData[i];       //mData = {12; 12} {12; 121}
    }
    return rhs;
}

DESolution DESolution::operator-(DESolution rhs) const
{
    for (size_t i = 0; i < mData.size(); ++i) {
        rhs.mData[i] = mData[i] - rhs.mData[i];
    }
    return rhs;
}

DESolution DESolution::operator-() const
{
    DESolution sol;                                 //crée une nouvelle instance
    
    sol.mData.resize(mData.size());                 //redimensionne sol.mData pour qu'il ait la même taille du mData courant
    for (size_t i{ 0 }; i < mData.size(); ++i) {
        sol.mData[i] = -mData[i];                   //À chaque itération, elle attribue à sol.mData[i] la valeur négative de mData[i]
    }
    return sol;                                     //Une fois la boucle terminée, elle retourne sol contenant les valeurs négatives des membres de mData de l'objet courant.
}

DESolution DESolution::operator*(double rhs) const
{
    DESolution sol;                      //crée une nouvelle instance de la classe DESolution appelée sol      

   sol.mData.resize(mData.size());      //redimensionne sol avec la meme taille du vecteur mData

    for (size_t i{ 0 }; i < mData.size(); ++i) {    //i represente l'index de couple

        sol.mData[i] = mData[i] * rhs;  //mData[i] accède à l'élément à l'index i dans le vecteur mData de l'objet courant (*this).
                                        //mData[i] * rhs multiplie l'élément mData[i] par le scalaire rhs.
                                        //sol.mData[i] affecte le résultat de la multiplication à l'élément correspondant dans le vecteur mData de l'objet sol.
    }

    return sol;                         //renvoie une copie de l'objet sol contenant les résultats de la multiplication.
}

DESolution DESolution::operator/(double rhs) const
{
    DESolution sol;

    sol.mData.resize(mData.size());

    for (size_t i{ 0 }; i < mData.size(); ++i) {
        sol.mData[i] = mData[i] / rhs;
    }

    return sol;
}

DESolution& DESolution::operator+=(DESolution const& rhs)
{
    for (size_t i = 0; i < mData.size(); ++i) {
        mData[i] += rhs.mData[i];
    }

    return *this;   //permet les operation en cascade
}

DESolution& DESolution::operator-=(DESolution const& rhs)
{
    for (size_t i = 0; i < mData.size(); ++i) {
        mData[i] -= rhs.mData[i];
    }

    return *this;
}

DESolution& DESolution::operator*=(double rhs)
{
    for (size_t i = 0; i < mData.size(); ++i) {
        mData[i] *= rhs;
    }

    return *this;
}

DESolution& DESolution::operator/=(double rhs)
{
    for (size_t i = 0; i < mData.size(); ++i) {
        mData[i] /= rhs;
    }

    return *this;
}
