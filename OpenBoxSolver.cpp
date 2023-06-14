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

	parameter.setObjFunc(&boxObjFunc);
	parameter.setFitnessFunc(boxFitFunc);

	mDEEngine.setup(parameter);


	mDEEngine.evolve();	//resoudre le probleme
}

//
//
//
////1. Au départ, un message d’accueil du logiciel est affiché. Ce message doit inclure :
//a.Le contexte de réalisation.
//b.Une présentation du projet(en 3 courtes phrases maximum).
//c.Le nom des auteurs.
//On attend l’appui sur une touche quelconque pour passer à l’étape suivante.
//2. On affiche un court texte présentant chacun des trois problèmes et on pose la question
//permettant de savoir lequel des trois problèmes est à résoudre.On offre aussi un
//quatrième choix permettant de quitter l’application.On attend que l’utilisateur ait fait
//la saisie.
//3. On présente le problème choisi et on pose les questions requises pour le problème.
//Lorsque toutes les réponses ont été répondues, on passe à l’étape suivante.
//4. La simulation correspondante est lancée.Lorsque le résultat est obtenu, les résultats
//sont affichés.C’est à vous de trouver la meilleure façon de représenter les résultats
//obtenus.On affiche un texte invitant l’utilisateur à appuyer sur une touche lorsqu’il aura
//terminé de consulter les résultats pour poursuivre à l’étape suivante.
//5. On retourne à l’étape 2.
//
//
//
//
//
//
std::string OpenBoxSolver::problemPresentation()
{

	return "Nous allons maintenant tester l'engin  contre le classique : le probleme de la boite ouverte.";
}

std::string OpenBoxSolver::solutionPresentation()
{
	return std::string(); //text
}

double boxObjFunc(const DESolution& solution)
{
	double width = 100;	//valeur fix
	double height = 50;	//valeur fix
	double volume=0;
	
	//const std::vector<double>& data = solution.;


	//volume = (width - (2.0 * x)) * (height - (2.0 * x)) * x;

	return volume;
	
}

double boxFitFunc(double db)
{
	return 0.0;
}
