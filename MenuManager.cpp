#include "menuManager.h"


MenuManager::MenuManager()
	:mImages{},
	mResizeX{},
	mResizeY{}
{
}

MenuManager::MenuManager(size_t nbImages)
{
	setNbImages(nbImages);
}

MenuManager::MenuManager(size_t nbImages, size_t widthX, size_t heightY)
{
	mResizeX = widthX;
	mResizeY = heightY;
	setNbImages(nbImages);
	for (size_t i{}; i < mImages.size(); ++i) {
		mImages[i].resize(widthX, heightY);
	}
	addMenuTrims(widthX, heightY);

	mainMenu();
}

MenuManager::~MenuManager()
{

}

void MenuManager::setNbImages(size_t nbImages)
{
	imageErrorHandling(nbImages);
	mImages.resize(nbImages);
}


void MenuManager::mainMenu()
{

	std::string openBox = "1. Open Box Solver.";
	std::string threePeaks = "2. Three Peaks Solver.";
	std::string prodOpti = "3. Production Optimisation for a Manufacture.";
	std::string quit = "8. Exit Program.";
	std::string upOneLevel = "7. Up One Level.";


	mImages[eSplashScreen].textH(eLeftToRightX, eMenuListYStart,      "Dans le cadre du cours de GPA-434, l'equipe composee des membres Guillaume Bourgeois et Jacob Curiel-Garfias");
	mImages[eSplashScreen].textH(eLeftToRightX, eMenuListYStart+1.0,  "ont assemble et programme le code permettant d'utiliser un engin d'évolution differentielle. Dans sa presente");
	mImages[eSplashScreen].textH(eLeftToRightX, eMenuListYStart+2.0,  "implementation, nous pouvons tester les capacites de cet engin en le confrontant à 3 problematiques ");
	mImages[eSplashScreen].textH(eLeftToRightX, eMenuListYStart+3.0,  "mathematiques differentes.");
	mImages[eSplashScreen].textH(eLeftToRightX, eMenuListYStart+16.0, "Press the any key.");

	mImages[eMainMenu].textH(eLeftToRightX, eMenuListYStart, openBox);

	mImages[eMainMenu].textH(eLeftToRightX, size_t(eMenuListYStart + eMenuListYSpacing), threePeaks);
	mImages[eMainMenu].textH(eLeftToRightX, size_t(eMenuListYStart + eMenuListYSpacing*2), prodOpti);
	mImages[eMainMenu].textH(eLeftToRightX, size_t(eMenuListYStart + eMenuListYSpacing*4), upOneLevel);
	mImages[eMainMenu].textH(eLeftToRightX, size_t(eMenuListYStart + eMenuListYSpacing*5), quit);

	size_t keyHit{ eMainMenu };
	//question enumeration
	
	

	consoleManager(mImages[eSplashScreen]);
	keyHit = _getch();
	consoleManager(mImages[eMainMenu]);
	keyHit = _getch();


	switch (keyHit) {
		

		case eOpenBoxSolver+ eASCIIConversion-1:
			problemMenus(eOpenBoxSolver);
			break;

		case eThreePeaks+ eASCIIConversion-1:
			problemMenus(eThreePeaks);
			break;

		case eFactoryProblem+ eASCIIConversion-1: 
			problemMenus(eFactoryProblem);
			break;

		case eExitProgram+ eASCIIConversion-1:
			exit(EXIT_SUCCESS);
			break;

		//default:
		//	consoleManager(mImages[eMainMenu]);
		//	keyHit = _getch();

	}


	
}

void MenuManager::problemMenus(size_t frameNumber)
{
	OpenBoxSolver boxSolver;
	PeaksSolver peaksSolver;
	FactoryProductionSolver productionSolver;
	std::string getFText{"Veuillez entrer une valeur pour F (poids differentiel) comprise entre [0.0 ; 2.0]."};
	std::string getCRText{"Veuillez entrer une valeur pour CR (probalite de croisement) comprise entre [0.0 ; 1.0]."};
	double parametersFetch{};
	size_t keyHit{ eMainMenu };

		switch (frameNumber) {


		case eOpenBoxSolver:
			mImages[eOpenBoxSolver].textH(eLeftToRightX, eMenuListYStart, boxSolver.problemPresentation());
			consoleManager(mImages[eOpenBoxSolver]);
			mImages[eOpenBoxSolver].textH(eLeftToRightX, eMenuListYStart+5, getFText );
			consoleManager(mImages[eOpenBoxSolver]);
			std::cin >> parametersFetch;
			boxSolver.getmDEEngine().getParameters().setCR(parametersFetch);
			
			mImages[eOpenBoxSolver].textH(eLeftToRightX, eMenuListYStart+7, getCRText );
			consoleManager(mImages[eOpenBoxSolver]);
			std::cin >> parametersFetch;
			boxSolver.getmDEEngine().getParameters().setF(parametersFetch);
			mImages[eOpenBoxSolver].textH(eLeftToRightX, eMenuListYStart + 9, "Veuillez appuyer sur une touche afin de demarrer l'engin de resolution.");
			consoleManager(mImages[eOpenBoxSolver]);
			keyHit = _getch();

			boxSolver.solve(50,100); // solve
			consoleManager(mImages[eOpenBoxSolution]);

			keyHit = _getch();


			break;

		case eThreePeaks:
			mImages[eOpenBoxSolver].textH(eLeftToRightX, eMenuListYStart, peaksSolver.problemPresentation());
			consoleManager(mImages[eOpenBoxSolver]);
			peaksSolver.solutionPresentation();
			keyHit = _getch();
			break;

		case eFactoryProblem:
			mImages[eOpenBoxSolver].textH(eLeftToRightX, eMenuListYStart, productionSolver.problemPresentation());
			consoleManager(mImages[eOpenBoxSolver]);
			productionSolver.solutionPresentation();
			keyHit = _getch();
			break;

		case eUpOneLevel:
			mainMenu();
			break;

		case eExitProgram:
			exit(EXIT_SUCCESS);
			break;


		}




}


void MenuManager::addMenuTrims(size_t widthX, size_t heightY)
{
	size_t outerRectOriginX{ 1 };
	size_t outerRectOriginY{ 1 };
	std::string topTitle = "Differential Evolution";

	mImages[0].CenteredTopTitle(mResizeX, outerRectOriginY, topTitle);
	
	for (size_t i{ 0 }; i < mImages.size(); i++) {

		mImages[i].drawRect(outerRectOriginX, outerRectOriginY, mResizeX - 1, mResizeY - 1);
		mImages[i].drawRect(outerRectOriginX + 1, outerRectOriginY + 1, outerRectOriginX + 4, outerRectOriginY + 3);
		mImages[i].drawRect(mResizeX - 2, mResizeY - 2, mResizeX - 5, mResizeY - 4);
		mImages[i].drawRect(outerRectOriginX + 1, mResizeY - 2, outerRectOriginX + 4, mResizeY - 4);
		mImages[i].drawRect(mResizeX - 2, outerRectOriginX + 1, mResizeX - 5, outerRectOriginY + 3);
	}

}

void MenuManager::imageErrorHandling(size_t nbImages)
{
	if (nbImages < 10 || nbImages > 100) {
		std::cout << "invalid number of images size";
		exit(EXIT_FAILURE);
	}

}

void MenuManager::consoleManager(StringImage frame)
{
	std::cout<<frame.toString();
}

StringImage& MenuManager::operator[](size_t index)
{
	return mImages[index];
}




