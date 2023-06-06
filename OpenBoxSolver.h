#pragma once
#ifndef OpenBoxSolver_h
#define OpenBoxSolver_h
#include "DifferentialEvolution.h"

class OpenBoxSolver {
	DifferentialEvolution mDEEngine;

public:
	void solve(size_t width, size_t height);
	std::string problemPresentation();
	std::string solutionPresentation();
};















#endif // OpenBoxSolver_h




































//
//
//
//
//
//
//
//
//
// classe open box problem
// 
// width
// height
// -----------------------------------------------------------
// 
// 
// 
// 
// 
// 
// exterieur de classe
// double fonction objective(DESolution const &)
// calcule si c bon ou pas
//()operateur dexecutiion
// double operator()(DESolution const &)
// functor est un objet executable. un objet dont les parentheses sont surchargees
// une fonction conventionnelle ne permet pas de gerer des donnees habilement 
//
//
//