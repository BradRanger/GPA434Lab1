#pragma once
#ifndef INTERVAL_H
#define INTERVAL_H

class Interval
{
public:

	//constructeur
	Interval();
	Interval(double lower, double upper);
	//getter
	double lower() const;
	double upper() const { return mUpper; }
	//setter

	void setLower(double);
	void setUpper(double);
	void set(double lower, double upper);
	double randomize();
	//destructeur
	~Interval();
private:

	double mLower;//member lower
	double mUpper;//member upper



};






#endif