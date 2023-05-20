#include "Interval.h"
#include "ThreeSamplesWithOneExclusion.h"
#include "DEParameters.h"
#include "DEPopulation.h"
#include "DESolutionBounds.h"
#include "DESolution.h"


//
// 
// 
// 1 vecteur actuel
// --2 dimensions x et y
// 
// 
// mutant va prendre des actuels et se composer des actuels
// et shuffle
// cela permet de tester des parametres qui peuvent etre eloignes les uns des autres
// mutant va evaluer deux autres aleatoires en fonction de lui meme
// 1 vecteur mutant
// --2 dimensions
// 1 vecteur test
//--2 dimensions
//on initialise tout a une valeur aleatoire
// 
// 
// 
// 
// 
//

void testInterval();
void testRandomize();

int main()
{

	testRandomize();

	return 0;
}

void testInterval()
{

	Interval interval(10, 20);

	interval.setUpper(15);
	interval.setLower(5);

}

void testRandomize()
{
	DESolutionBounds deso;		//la variable appel elle meme son constructeur

	for (int i{}; i < deso.solutionBounds().size(); ++i) {

		deso.solutionBounds()[i].randomize();
	}


}



//test

//TEST 2

//test3

//test 4

//test 5