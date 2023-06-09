#pragma once
#ifndef MenuManager_H
#define MenuManager_H
#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include "StringImage.h"



class MenuManager
{

private:
	std::vector<StringImage> mImages;

public:


	MenuManager();
	~MenuManager();
	void setNbImages(unsigned int howManyImg);

	StringImage& operator[](size_t index);

};







#endif