#include "Interval.h"
#include "ThreeSamplesWithOneExclusion.h"
#include "DEParameters.h"
#include "DEPopulation.h"
#include "DESolutionBounds.h"
#include "DESolution.h"
#include "StringImage.h"
#include "conio.h"
#include "OpenBoxSolver.h"
#include "PeaksSolver.h"
#include "FactoryProductionSolver.h"
#include <windows.h>

//
// 
// 
// 1 vecteur actuel
// --2 dimensions x et y
// 
// 
// mutant va prendre des actuels et se composer des actuels
// et shuffle
// cela permet de tester des parametres qui peuvent etre eloignes les uns des autres
// mutant va evaluer deux autres aleatoires en fonction de lui meme
// 1 vecteur mutant
// --2 dimensions
// 1 vecteur test
//--2 dimensions
//on initialise tout a une valeur aleatoire
// 
// 
// 
// 
// 
//

//void testInterval();
//void testRandomize();
//
int main()
{
	bool endProg{ true };
	StringImage menu;
	int resizeX{ 117 };
	int resizeY{ 30 };
	std::string topTitle = "Differential Evolution" ;
	std::string openBox = "1. Open Box Solver." ;
	std::string threePeaks = "2. Three Peaks Solver.";
	std::string prodOpti = "3. Production Optimisation for a Manufacture.";


	menu.resize(resizeX, resizeY);
	menu.drawRect(1, 1, resizeX-1, resizeY-1);
	menu.textH(((resizeX - (int)topTitle.size()) / 2), 2, topTitle);
	menu.textH(3,6,openBox);
	menu.textH(3,8,threePeaks);
	menu.textH(3,10,prodOpti);




	//l'animation doit etre integree dans limage avant detre affichee
	std::cout << menu.toString();//affiche image
	Sleep(70000);

	//std::system("cls");//clear screen



	return 0;
}


