#include "StringImage.h"

StringImage::StringImage()
	: mWidth{}
	, mHeight{}
	, mImage("")
{
}


StringImage::StringImage(int width, int height, char fillChar)
{
	resize(width, height);
}




StringImage::StringImage(int squaredDimension, char fillChar)
	: StringImage(squaredDimension, squaredDimension, fillChar)
{
}

StringImage::~StringImage()
{
}

//returns width of generated image
int StringImage::width()
{
	return mWidth;
}

//returns height of generated image
int StringImage::height()
{
	return mHeight;
}

//returns char value at (x,y)
char StringImage::read(int x, int y)
{
	if (isValid(x, y)) {
		return mImage[index(x, y)];
	}
	else {
		return '\0';
	}
}

//returns the string value that represents the image
std::string StringImage::toString()
{
	return mImage;
}

//sets the default background tile

//gives a new size of the window that is the image itself
//also regenerates to default background tile
void StringImage::resize(int new_width, int new_height)
{
	// si l'une des dimensions est égale à 0
	if (new_width == 0 || new_height == 0) {
		mWidth = 0;
		mHeight = 0;
		mImage = "";
	}
	else {
		// validation de la borne supérieure : clamping
		if (new_width > 1000) {
			new_width = 1000;
		}
		new_height = std::min(new_height, (int)1000);

		mWidth = new_width;
		mHeight = new_height;

		fill();
	}
}

//fills whole image with specified character
//right now, it is tied to the StringImage::fillChar
void StringImage::fill()
{
	size_t nChar = (size_t)(mWidth + 1) * mHeight;
	mImage = std::string(nChar, (char)LineChar::FillChar);
	for (size_t row = 0; row < mHeight; ++row) {
		mImage[row * (size_t)(mWidth + 1) + mWidth] = '\n';
	}
}

void StringImage::write(int x, int y, char pixelChar)
{
	if (isValid(x, y)) {
		mImage[index(x, y)] = pixelChar;
	}
}


void StringImage::erase(int x, int y)
{
	write(x, y, (char)LineChar::FillChar);
}

int StringImage::index(int x, int y)
{
	return y * (mWidth + 1) + x;
}
bool StringImage::isValid(int x, int y)
{
	return x >= 0 && x < mWidth && y >= 0 && y < mHeight;
}

void StringImage::drawHLine(int x, int y, int length)
{

	for (int i = 0; i < length; ++i) {



		StringImage::write(x + i, y, (char)LineChar::HLine);

	}
}

void StringImage::drawVLine(int x, int y, int length)
{
	for (int i = 0; i < length; ++i) {

		StringImage::write(x, y + i, (char)LineChar::VLine);


	}

}

void StringImage::drawHThckLine(int x, int y, int length)
{
	for (int i = 0; i < length; ++i) {

		StringImage::write(x + i, y, (char)LineChar::FullSquare);
	}

}

void StringImage::drawVThckLine(int x, int y, int length)
{
	for (int i = 0; i < length; ++i) {

		StringImage::write(x, y + i, (char)LineChar::FullSquare);


	}

}

void StringImage::textH(int x, int y, std::string text)
{
	for (int i = 0; i < text.length(); i++) {
		StringImage::write(x + i, y, text.at(i));
	}

}

void StringImage::textV(int x, int y, std::string text) {

	{
		for (int i = 0; i < text.length(); i++) {
			StringImage::write(x, y + i, text.at(i));
		}

	}

}

void StringImage::drawRect(int x1, int y1, int x2, int y2)
{

	int sx = 0; //start x
	if (x1 <= x2) {

		sx = x1;


	}
	else if (x1 >= x2) {

		sx = x2;
	}

	int sy = 0; //start y
	if (y1 <= y2) {

		sy = y1;

	}
	else if (y1 >= y2) {
		sy = y2;

	}

	int ex = 0; //end x
	if (x1 >= x2) {
		ex = x1;

	}
	else if (x1 <= x2) {
		ex = x2;

	}

	int ey = 0; //end y
	if (y1 >= y2) {
		ey = y1;

	}
	else if (y1 <= y2) {
		ey = y2;

	}



	StringImage::write(sx, sy, (char)LineChar::TopLCorner);
	StringImage::drawHLine(sx + 1, sy, ex - sx - 2);
	StringImage::drawHLine(sx + 1, sy + ey - sy - 1, ex - sx - 2);
	StringImage::write(sx, +sy + ey - sy - 1, (char)LineChar::BotLCorner);


	StringImage::write(sx + (ex - sx) - 1, sy, (char)LineChar::TopRCorner);
	StringImage::drawVLine(sx, sy + 1, ey - sy - 2);
	StringImage::drawVLine(sx + ex - sx - 1, sy + 1, ey - sy - 2);
	StringImage::write(sx + (ex - sx) - 1, sy + (ey - sy) - 1, (char)LineChar::BotRCorner);




}
//Draws a Microsoft Word like table. 
// x1 and y1 for starting pos
//number of rows, length of rows, number of columns, height of columns

