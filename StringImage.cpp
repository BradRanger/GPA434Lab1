#include "StringImage.h"

StringImage::StringImage()
	: mWidth{}
	, mHeight{}
	, mImage("")
{
}


StringImage::StringImage(size_t width, size_t height, char fillChar)
{
	resize(width, height);
}




StringImage::StringImage(size_t squaredDimension, char fillChar)
	: StringImage(squaredDimension, squaredDimension, fillChar)
{
}

StringImage::~StringImage()
{
}

//returns width of generated image
size_t StringImage::width()
{
	return mWidth;
}

//returns height of generated image
size_t StringImage::height()
{
	return mHeight;
}

//returns char value at (x,y)
char StringImage::read(size_t x, size_t y)
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
void StringImage::resize(size_t new_width, size_t new_height)
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
		new_height = std::min(new_height, (size_t)1000);

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

void StringImage::write(size_t x, size_t y, char pixelChar)
{
	if (isValid(x, y)) {
		mImage[index(x, y)] = pixelChar;
	}
}


void StringImage::erase(size_t x, size_t y)
{
	write(x, y, (char)LineChar::FillChar);
}

size_t StringImage::index(size_t x, size_t y)
{
	return y * (mWidth + 1) + x;
}

bool StringImage::isValid(size_t x, size_t y)
{
	return x >= 0 && x < mWidth && y >= 0 && y < mHeight;
}

void StringImage::drawHLine(size_t x, size_t y, size_t length)
{

	for (int i = 0; i < length; ++i) {



		StringImage::write(x + i, y, (char)LineChar::HLine);

	}
}

void StringImage::drawVLine(size_t x, size_t y, size_t length)
{
	for (size_t i{}; i < length; ++i) {

		StringImage::write(x, y + i, (char)LineChar::VLine);


	}

}

void StringImage::drawHThckLine(size_t x, size_t y, size_t length)
{
	for (size_t i{}; i < length; ++i) {

		StringImage::write(x + i, y, (char)LineChar::FullSquare);
	}

}

void StringImage::drawVThckLine(size_t x, size_t y, size_t length)
{
	for (size_t i = 0; i < length; ++i) {

		StringImage::write(x, y + i, (char)LineChar::FullSquare);


	}

}

void StringImage::textH(size_t x, size_t y, std::string text)
{

	size_t lineLength{ 60 };

	if (text.size() < 1){
		exit(EXIT_FAILURE);
	}

	if( text.size()<= lineLength){
		for (int i = 0; i < text.length(); i++) {
			write(x + i, y, text.at(i));
		}
	}

	if(text.size() > lineLength){
	std::vector<std::string> dividedString;

	size_t stringCursor{};
	size_t nbOfRows{ 1 };

	nbOfRows = std::ceil(text.size() / lineLength);

	dividedString.resize(nbOfRows);

	for (size_t i{}; i < nbOfRows; ++i) {
		dividedString[i] = text.substr(0, lineLength);
		textH(x, y, dividedString[i]);

	}

	}

}

void StringImage::textV(size_t x, size_t y, std::string text) {

	{
		for (size_t i{}; i < text.length(); i++) {
			StringImage::write(x, y + i, text.at(i));
		}

	}

}

void StringImage::CenteredTopTitle(size_t resizeX, size_t outerRectOriginY, std::string title)
{
	textH(((resizeX - (size_t)title.size()) / 2), outerRectOriginY + 1, title);
}

void StringImage::drawRect(size_t x1, size_t y1, size_t x2, size_t y2)
{
	//since drawHLine works from left to right and drawVLine draws from top to bottom, I made it so that the starting points 
	//for the line origins were easier for me to understand when creating the rectangle pattern.
	size_t sx = 0; //start x
	if (x1 <= x2) {

		sx = x1;


	}
	else if (x1 >= x2) {

		sx = x2;
	}

	size_t sy = 0; //start y
	if (y1 <= y2) {

		sy = y1;

	}
	else if (y1 >= y2) {
		sy = y2;

	}

	size_t ex = 0; //end x
	if (x1 >= x2) {
		ex = x1;

	}
	else if (x1 <= x2) {
		ex = x2;

	}

	size_t ey = 0; //end y
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

