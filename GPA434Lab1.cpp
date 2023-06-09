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



	
	
	for (size_t i{}; i < 99999999999; ++i) {

	}
	
	
	switch (size_t option{}) {

		option = (size_t)_getch;

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


