#pragma once
#ifndef INTERVAL_H
#define INTERVAL_H

class Interval
{
private:

	double mLower; //member lower
	double mUpper; //member upper

public:

	//constructeur
	Interval();
	Interval(double lower, double upper);
	//getter
	double lower() const;
	double upper() const;
	//setter

	void setLower(double);
	void setUpper(double);
	void set(double lower, double upper);
	double randomize() const;
	//destructeur
	~Interval();


};

#endif