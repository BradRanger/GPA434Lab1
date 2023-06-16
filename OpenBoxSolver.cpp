#include "OpenBoxSolver.h"

OpenBoxSolver::OpenBoxSolver()
	:mDEEngine{}
{
}

OpenBoxSolver::~OpenBoxSolver()
{
}

DifferentialEvolution OpenBoxSolver::getmDEEngine() const
{
	return mDEEngine;
}

void OpenBoxSolver::solve(size_t width, size_t height)
{
	//parametriser toutes les valeurs

	DEParameters parameter;
	DESolutionBounds xBounds;
	double maxWidth = width / 2.0;
	double maxHeight = height / 2.0;

	Interval vec;


	/*
	vec.set(0.0, maxWidth);
	xBounds.solutionBounds().push_back(vec);
	vec.set(0.0, maxHeight);
	xBounds.solutionBounds().push_back(vec);
	*/

	
	xBounds.solutionBounds().push_back(Interval(0.0, maxWidth)); 
	xBounds.solutionBounds().push_back(Interval(0.0, maxHeight)); 
	
	parameter.setSolutionBounds(xBounds);

	parameter.setMaxGenerationCount(15);
	parameter.setPopulationSize(100);

	parameter.setObjFunc(&boxObjFunc);			//envoie l<adress de la fonction boxObjFunc 
	parameter.setFitnessFunc(&boxFitFunc);		//envoi l'adress de la fonction boxFitFunc 

	mDEEngine.setup(parameter);


	mDEEngine.evolve();
}

std::vector<std::string> OpenBoxSolver::problemPresentation()
{
	std::vector<std::string> boxProblemPres;
	boxProblemPres.resize(2);
	boxProblemPres[0] = "Nous allons maintenant tester l'engin  contre le classique : le probleme de la boite ouverte.";
	return boxProblemPres;
}

std::vector<std::string> OpenBoxSolver::solutionPresentation()
{
	std::vector<std::string> boxProblemSol;
	boxProblemSol.resize(1);
	boxProblemSol[0] = "dhadf ";
	return boxProblemSol; 
}

double boxObjFunc(const DESolution& solution)
{
	double x = solution.getData()[0];

	return x;
}

double boxFitFunc(double x)
{

	double volume = (100 - (2.0 * x)) * (50 - (2.0 * x)) * x;	// Calcule le volume de la boîte ouverte

	return volume;
}
