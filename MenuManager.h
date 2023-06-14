#pragma once
#ifndef MenuManager_H
#define MenuManager_H
#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include "OpenBoxSolver.h"
#include "PeaksSolver.h"
#include "FactoryProductionSolver.h"
#include "StringImage.h"


class MenuManager 
{
	size_t mResizeX;
	size_t mResizeY;
	std::vector<StringImage> mImages;
	std::string mAnyKey;
	
	enum MenuOptions {

		eExitProgram = 8,
		eUpOneLevel = 7,

		//Main menu options
		eSplashScreen = 0,
		eMainMenu = 1,
		eOpenBoxSolver = 2,
		eThreePeaks = 3,
		eFactoryProblem = 4,
		eOpenBoxSolution = 5,
		eThreePeaksSolution = 6,
		eFactorySolution = 7,

		//Sub menus options
		eSolve = 1,
		eContinue = 32,
		eASCIIConversion = 48

	};

	// The only reason I do not drive my menu items with equations (true parametry) is because of the console limitations.
	// I wanted to avoid awkward spacing that could be provoked by a rounded number since the height (y axis) spaces
	// are really noticeable. I made this choice for design purposes only.
	enum MenuItemsXY {
		eLeftToRightX = 3,
		eMenuListYStart = 6,
		eMenuListYSpacing = 2,
	};

public:

	//construction and destruction
	MenuManager();
	MenuManager(size_t nbImages);
	MenuManager(size_t nbImages, size_t widthX, size_t heightY);
	~MenuManager();



	void setNbImages(size_t nbImages);
	void mainMenu();
	void problemMenus(size_t frameNumber);
	void addMenuTrims(size_t widthX, size_t heightY);
	void imageErrorHandling(size_t nbImages);

	void consoleManager(StringImage frame);
	StringImage& operator[](size_t index);

};



//QUESTIONS PROF
//
//




#endif