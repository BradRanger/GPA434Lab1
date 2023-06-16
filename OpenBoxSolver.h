#pragma once
#ifndef OpenBoxSolver_h
#define OpenBoxSolver_h
#include "DifferentialEvolution.h"

class OpenBoxSolver {
	DifferentialEvolution mDEEngine;

public:
	friend double boxObjFunc(const DESolution& solution);

	OpenBoxSolver();
	~OpenBoxSolver();

	DifferentialEvolution getmDEEngine() const;

	void solve(size_t width, size_t height);
	std::vector<std::string> problemPresentation();
	std::vector<std::string> solutionPresentation();


};


double boxObjFunc(const DESolution& solution) ;
double boxFitFunc(double x) ;






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