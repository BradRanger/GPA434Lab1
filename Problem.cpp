#include "Problem.h"

float Problem::operator()(float value)
{
	return value * depth + size;
}
