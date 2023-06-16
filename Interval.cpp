#include "Interval.h"
#include <random>

Interval::Interval()
	:Interval(0,1) // constructeur delegue
{
}

Interval::Interval(double lower, double upper) 
{
	set(lower, upper);
}

double Interval::lower() const
{
	return mLower;
}

double Interval::upper() const
{
	return mUpper;
}

void Interval::setLower(double lower)
{
	set( lower, mUpper);
}

void Interval::setUpper(double upper)
{
	set(mLower, upper);
}

void Interval::set(double lower, double upper)

{
	if (lower > upper) {
		

		lower = upper;
	}
	mLower = lower;
	mUpper = upper;
}

double Interval::randomize() const
{
	std::default_random_engine generator; //
	//fonction de densite
	std::uniform_real_distribution<double> distribution(mLower, mUpper);

	return distribution(generator);
}

Interval::~Interval()
{
}
