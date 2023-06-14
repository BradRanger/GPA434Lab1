#include "Interval.h"
#include "ThreeSamplesWithOneExclusion.h"
#include "DEParameters.h"
#include "DEPopulation.h"
#include "DESolutionBounds.h"
#include "DESolution.h"
#include "conio.h"
#include <windows.h>
#include "MenuManager.h"
#include "OpenBoxSolver.h"


int main()
{


	
	MenuManager menu(11,117,29);


	/*****************************************Open box*********************************/

	OpenBoxSolver box;

	double f = 2;
	double cr = 1;


	box.problemPresentation();




	box.solve(100, 50);


	/**SAISIR LA VALEUR DU PARAMETRE F***/
	//par défaut F = 2
	//SAISIE F DANS L'INTERVALLE [0.0, 2.0]


	box.getmDEEngine().getParameters().setF(f);	//mettre la valeur par defaut
	




	/**SAISIR LA VALEUR DU PARAMETRE CR***/
	//par défaut CR = 1
	//SAISIE F DANS L'INTERVALLE [0.0, 1.0]


	box.getmDEEngine().getParameters().setCR(cr);	//mettre la valeur par defaut



	/*****/


	box.solutionPresentation();





	

}


