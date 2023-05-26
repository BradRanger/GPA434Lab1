#pragma once
#ifndef FUNCTIONDECLARATION_H
#define FUNCTIONDECLARATION_H
#include "DESolution.h"

using de_objective_function_t = double(*)(DESolution const& Solution);
using de_fitness_function_t = double(*)(double);







#endif FUNCTIONDECLARATION_H