#include "Interval.h"
#include "ThreeSamplesWithOneExclusion.h"
#include "DEParameters.h"
#include "DEPopulation.h"
#include "DESolutionBounds.h"
#include "DESolution.h"
#include "StringImage.h"
#include "conio.h"

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

//void testInterval();
//void testRandomize();
//
int main()
{
	bool endProg{ true };
	StringImage menu;

	menu.resize(60, 20);
	menu.drawRect(1, 1, 59, 19);
	while (endProg) {


		//l'animation doit etre integree dans limage avant detre affichee
		std::cout << menu.toString();//affiche image


			//std::system("cls");//clear screen



	}

	return 0;
}


