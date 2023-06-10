#pragma once
#ifndef STRING_IMAGE_H
#define STRING_IMAGE_H

#include <iostream>
#include <cmath>
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>
#include "LineChar.h"
class StringImage
{
public:

	// Constructeurs
	StringImage();
	StringImage(size_t width, size_t height, char fillChar);
	StringImage(size_t squaredDimension, char fillChar = ' ');

	// Destructeur
	~StringImage();

	// accesseurs
	size_t width();
	size_t height();
	char read(size_t x, size_t y);
	std::string toString();
	// mutateurs


	void resize(size_t new_width, size_t new_height);
	void fill();

	void write(size_t x, size_t y, char pixelChar);

	bool isValid(size_t x, size_t y);
	void drawHLine(size_t x, size_t y, size_t length);
	void drawVLine(size_t x, size_t y, size_t length);
	void drawHThckLine(size_t x, size_t y, size_t length);
	void drawVThckLine(size_t x, size_t y, size_t length);

	void textH(size_t x, size_t y, std::string text);
	void textV(size_t x, size_t y, std::string text);
	void CenteredTopTitle(size_t resizeX, size_t outerRectOriginY, std::string title);

	void drawRect(size_t x1, size_t y1, size_t x2, size_t y2);

	void erase(size_t x, size_t y);


private:
	std::string mImage;
	size_t mWidth;
	size_t mHeight;
	size_t index(size_t x, size_t y);

};




#endif // STRING_IMAGE_H