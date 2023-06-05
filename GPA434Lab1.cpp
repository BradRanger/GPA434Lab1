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


int main()
{
	bool endProg{ true };
	StringImage menu;
 
	int resizeX{ 117 };
	int resizeY{ 29 };


	int outerRectOriginX{ 1 };
	int outerRectOriginY{ 1 };

	std::string topTitle = "Differential Evolution" ;
	std::string openBox = "1. Open Box Solver." ;
	std::string threePeaks = "2. Three Peaks Solver.";
	std::string prodOpti = "3. Production Optimisation for a Manufacture.";
	menu.resize(resizeX, resizeY);
	//outer rect is supposed to create a steady parametric display 

	menu.drawRect(outerRectOriginX, outerRectOriginY, resizeX - 1, resizeY - 1);


	menu.textH(((resizeX - (int)topTitle.size()) / 2), outerRectOriginY+1, topTitle);
	menu.textH(3, 6, openBox);
	menu.textH(3, 8, threePeaks);
	menu.textH(3, 10,prodOpti);
	menu.drawRect(outerRectOriginX+1, outerRectOriginY+1, outerRectOriginX+4, outerRectOriginY+3);
	menu.drawRect(resizeX-2, resizeY-2, resizeX-5, resizeY-4);
	menu.drawRect(outerRectOriginX+1,resizeY-2 , outerRectOriginX+4, resizeY-4);
	menu.drawRect(resizeX-2, outerRectOriginX+1, resizeX-5, outerRectOriginY+3);




	std::cout << menu.toString();//affiche image
	Sleep(70000);


	  
	std::system("cls");//clear screen



	return 0;
}


