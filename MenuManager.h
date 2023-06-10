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
	
	enum MenuOptions {

		ExitProgram = 8,
		UpOneLevel = 7,

		MainMenu = 0,
		OpenBoxSolver = 1,
		ThreePeaks = 2,
		FactoryProblem = 3,

		Solve = 1,
		Continue = 32

	};

public:

	//construction and destruction
	MenuManager();
	MenuManager(size_t nbImages);
	MenuManager(size_t nbImages, size_t widthX, size_t heightY);
	~MenuManager();



	void setNbImages(size_t nbImages);
	void mainMenu();
	void subMenus(size_t frameNumber);
	void addMenuTrims(size_t widthX, size_t heightY);
	void imageErrorHandling(size_t nbImages);

	void consoleManager(StringImage frame);
	StringImage& operator[](size_t index);

};







#endif