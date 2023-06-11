#include "OpenBoxSolver.h"

void OpenBoxSolver::solve(size_t width, size_t height)
{

	size_t x{ 1 };
	size_t volume{ (width - (2 * x) * height - (2 * x))*x };


	mDEEngine.evolve();
	mDEEngine.evolveOne();
	mDEEngine.isReady();
}

//
//
//
////1. Au d�part, un message d�accueil du logiciel est affich�. Ce message doit inclure :
//a.Le contexte de r�alisation.
//b.Une pr�sentation du projet(en 3 courtes phrases maximum).
//c.Le nom des auteurs.
//On attend l�appui sur une touche quelconque pour passer � l��tape suivante.
//2. On affiche un court texte pr�sentant chacun des trois probl�mes et on pose la question
//permettant de savoir lequel des trois probl�mes est � r�soudre.On offre aussi un
//quatri�me choix permettant de quitter l�application.On attend que l�utilisateur ait fait
//la saisie.
//3. On pr�sente le probl�me choisi et on pose les questions requises pour le probl�me.
//Lorsque toutes les r�ponses ont �t� r�pondues, on passe � l��tape suivante.
//4. La simulation correspondante est lanc�e.Lorsque le r�sultat est obtenu, les r�sultats
//sont affich�s.C�est � vous de trouver la meilleure fa�on de repr�senter les r�sultats
//obtenus.On affiche un texte invitant l�utilisateur � appuyer sur une touche lorsqu�il aura
//termin� de consulter les r�sultats pour poursuivre � l��tape suivante.
//5. On retourne � l��tape 2.
//
//
//
//
//
//
std::string OpenBoxSolver::problemPresentation()
{
	return "";
}

std::string OpenBoxSolver::solutionPresentation()
{
	return std::string();
}
