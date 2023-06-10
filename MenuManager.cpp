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

	mImages[MenuOptions::MainMenu].textH(3, 6, openBox);
	mImages[MenuOptions::MainMenu].textH(3, 8, threePeaks);
	mImages[MenuOptions::MainMenu].textH(3, 10, prodOpti);

	size_t keyHit{ MenuOptions::MainMenu };
	//question enumeration
	
	
	do {
		consoleManager(mImages[MenuOptions::MainMenu]);
		keyHit = _getch();

		switch (keyHit) {
		
		case MenuOptions::OpenBoxSolver:
			subMenus(MenuOptions::OpenBoxSolver);
			break;

		case MenuOptions::ThreePeaks:
			subMenus(MenuOptions::ThreePeaks);
			break;

		case MenuOptions::FactoryProblem:
			subMenus(MenuOptions::FactoryProblem);
			break;

		case MenuOptions::ExitProgram:
			subMenus(MenuOptions::FactoryProblem);
			break;


		}


	} while (keyHit < 1 || keyHit < 4);
}

void MenuManager::subMenus(size_t frameNumber)
{
	size_t keyHit{ MenuOptions::MainMenu };

	switch (keyHit) {

		case MenuOptions::MainMenu:
			
			break;

		case MenuOptions::OpenBoxSolver:

			break;

		case MenuOptions::ThreePeaks:

			break;

		case MenuOptions::FactoryProblem:

			break;


	


} while (keyHit);


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




