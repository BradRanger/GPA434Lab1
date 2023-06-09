#include "Interval.h"
#include "ThreeSamplesWithOneExclusion.h"
#include "DEParameters.h"
#include "DEPopulation.h"
#include "DESolutionBounds.h"
#include "DESolution.h"
#include "conio.h"
#include "OpenBoxSolver.h"
#include "PeaksSolver.h"
#include "FactoryProductionSolver.h"
#include <windows.h>
#include "MenuManager.h"

int main()
{
	OpenBoxSolver box;
	PeaksSolver peaks;
	FactoryProductionSolver factory;

	unsigned int nbOfMenus{ 15 };
	MenuManager menus;
	menus.setNbImages(nbOfMenus);

	bool endProg{ true };
	 
	std::string topTitle = "Differential Evolution" ;
	std::string openBox = "1. Open Box Solver." ;
	std::string threePeaks = "2. Three Peaks Solver.";
	std::string prodOpti = "3. Production Optimisation for a Manufacture.";
	//outer rect is supposed to create a steady parametric display 

	//Base layout for every menu
	int resizeX{ 117 };
	int resizeY{ 29 };

	int outerRectOriginX{ 1 };
	int outerRectOriginY{ 1 };

	//All menu graphics
	for(int i{0}; i< nbOfMenus;i++){

	menus[i].resize(resizeX, resizeY);

	menus[i].drawRect(outerRectOriginX, outerRectOriginY, resizeX - 1, resizeY - 1);
	menus[i].drawRect(outerRectOriginX + 1, outerRectOriginY + 1, outerRectOriginX + 4, outerRectOriginY + 3);
	menus[i].drawRect(resizeX - 2, resizeY - 2, resizeX - 5, resizeY - 4);
	menus[i].drawRect(outerRectOriginX + 1, resizeY - 2, outerRectOriginX + 4, resizeY - 4);
	menus[i].drawRect(resizeX - 2, outerRectOriginX + 1, resizeX - 5, outerRectOriginY + 3);
	}	

	
	//Main menu
	menus[0].CenteredTopTitle(resizeX, outerRectOriginY, topTitle);
	menus[0].textH(3, 6, openBox);
	menus[0].textH(3, 8, threePeaks);
	menus[0].textH(3, 10,prodOpti);
	std::cout << menus[0].toString();//affiche image
	menus[1].textH(5, 5, box.problemPresentation());
	menus[2].textH(5, 5, peaks.problemPresentation());
	menus[3].textH(5, 5, factory.problemPresentation());

	std::cout << menus[1].toString();

	for (int i{}; i < 99999999999; ++i) {

	}
	
	switch (int option{}) {

		option = (int)_getch;

	case 1:
		std::cout << menus[1].toString();
		break;
	case 2:
		std::cout << menus[2].toString();//affiche image
		break;
	case 3:
		std::cout << menus[3].toString();
		break;
	}
	




	return 0;
}


