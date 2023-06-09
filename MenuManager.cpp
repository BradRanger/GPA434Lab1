#include "menuManager.h"
#include <math.h>

#define PI 3.1416


MenuManager::MenuManager()
	:mImages{}
{
	setNbImages(1);
}

MenuManager::~MenuManager()
{

}

void MenuManager::setNbImages(unsigned int howManyImg)
{
	
	if (howManyImg == 0) {
		exit(EXIT_FAILURE);
		}
	mImages.resize(howManyImg);
}

StringImage& MenuManager::operator[](size_t index)
{
	return mImages[index];
}




