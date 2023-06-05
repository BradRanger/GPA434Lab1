//#include <iostream>
//
//#include "Vect2D.h"
//#include "Population.h"
//
//#include "Solver.h"
//#include "Problem.h"
//
//int main()
//{
//	Vect2D v1, v2(1.5, -3.25), v3(1.0, 0.0), v4;
//
//	v3.set(0.0, -1.0);
//
//	if (v1 == v2) {
//		//...
//	}
//
//	v1 = v2 + (v3 - v4);
//	v1 = -v1;
//
//	v1 = v2 * 2.0;
//	v1 = v2 / 2.0;
//
//	v1 = 2.0 * v2;
//	v1 = 2.0 / v2;
//
//	v1 += v2;
//	v1 -= v2;
//
//	// -------------------------
//	Population pop;
//	pop.resize(100, Vect2D(1.0, 1.0));
//	pop[3].setX(100.0);
//
//	Population const & myCoolPop{ pop };
//	//myCoolPop[5].setX(100.0);
//
//	std::cout << v1 << std::endl;
//
//	// ------------------------
//
//	Problem prob;
//	prob.depth = 5;
//	prob.size = 10;
//	float value = prob(2.0f);
//
//	Solver solver;
//	solver.objectiveFunction = prob;
//	solver.process();
//
//
//	return 0;
//}