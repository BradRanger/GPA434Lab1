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

	xBounds.solutionBounds().push_back(Interval(0, width / 2)); // Bornes pour le côté supérieur gauche
	xBounds.solutionBounds().push_back(Interval(0, height / 2)); // Bornes pour le côté supérieur gauche

	xBounds.solutionBounds().push_back(Interval(0, width / 2)); // Bornes pour le côté supérieur droit
	xBounds.solutionBounds().push_back(Interval(0, height / 2)); // Bornes pour le côté supérieur droit

	xBounds.solutionBounds().push_back(Interval(0, width / 2)); // Bornes pour le côté inférieur gauche
	xBounds.solutionBounds().push_back(Interval(0, height / 2));// Bornes pour le côté inférieur gauche

	xBounds.solutionBounds().push_back(Interval(0, width / 2)); // Bornes pour le côté inférieur droit
	xBounds.solutionBounds().push_back(Interval(0, height / 2)); // Bornes pour le côté inférieur droit

	parameter.setSolutionBounds(xBounds);

	parameter.setMaxGenerationCount(15);
	parameter.setPopulationSize(100);

	parameter.setObjFunc(boxObjFunc(mDEEngine.getPopulation().getSolutions()[0]));
	parameter.setFitnessFunc(boxFitFunc);

	mDEEngine.setup(parameter);

	mDEEngine.evolve();	//resoudre le probleme
	//mDEEngine.getStatistics().add(mDEEngine.)

	mDEEngine.getStatistics().getStatistics()[0].size();

	boxObjFunc(mDEEngine.getStatistics().getStatistics()[0]);
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
	//double width{100};	//valeur fix
	//double height{ 50 };	//valeur fix
	double volume{};
	
	const std::vector<double>& data = solution.getData();//extrait les données
	double x = data[0];


	volume = (width - (2.0 * x)) * (height - (2.0 * x)) * x;
	
	return volume;
}

double boxFitFunc(double db)
{
	return db;
}
