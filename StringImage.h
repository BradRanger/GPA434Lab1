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
	StringImage(int width, int height, char fillChar);
	StringImage(int squaredDimension, char fillChar = ' ');

	// Destructeur
	~StringImage();

	// accesseurs
	int width();
	int height();
	char read(int x, int y);
	std::string toString();
	// mutateurs


	void resize(int new_width, int new_height);
	void fill();

	void write(int x, int y, char pixelChar);
	void erase(int x, int y);

	bool isValid(int x, int y);
	void drawHLine(int x, int y, int length);
	void drawVLine(int x, int y, int length);
	void drawHThckLine(int x, int y, int length);
	void drawVThckLine(int x, int y, int length);

	void textH(int x, int y, std::string text);
	void textV(int x, int y, std::string text);
	void drawRect(int x1, int y1, int x2, int y2);


private:
	std::string mImage;
	int mWidth;
	int mHeight;
	int index(int x, int y);

};




#endif // STRING_IMAGE_H