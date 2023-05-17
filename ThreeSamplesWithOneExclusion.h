//#pragma once
//#ifndef _THREE_SAMPLE_WITH_ONE_EXCLUSION_H_
//#define _THREE_SAMPLE_WITH_ONE_EXCLUSION_H_
//
//
//#include <vector>
//#include <random>
//
//
//// G�n�re trois �chantillons distincts. Les indexes s�lectionn�s sont 
//// diff�rents les uns des autres et diff�rents de l'exclusion indiqu�e.
//// 
//// Cette classe est un exemple r�alisant l'encapsulation d'un algorithme 
//// d�di� (aucunement g�n�rique).*** 
//// 
//// L'algorithme se d�roule en deux �tapes pour des consid�rations de 
//// performance dans un contexte o� plusieurs �chantillonnages avec la m�me 
//// source de donn�es sont r�alis�s.
////
//// La classe utilise les indexes � titre de r�f�rent. Autrement dit, elle 
//// n'utilise pas de pointeurs, de r�f�rences ou d'it�rateurs. La classe 
//// est ind�pendante du tableau source.
////
//// Exemple :
////
//// #include <vector>
//// #include "DESolution.h"
//// #include "ThreeSamplesWithOneExclusion.h"
////
//// int main() 
//// {
////		const size_t populationSize{ 100 };
////		std::vector<DESolution> solutions(populationSize);
////		ThreeSamplesWithOneExclusion samplingTool;
////
////		samplingTool.prepare(solutions.size());
////
////		size_t solutionIndex0, solutionIndex1, solutionIndex2;
////		for (int i{}; i < populationSize; ++i) {
////			samplingTool.select(i, solutionIndex0, solutionIndex1, solutionIndex2);
////			// do something with these three distinct solutions :
////			//	- solution[solutionIndex0] 
////			//	- solution[solutionIndex1]
////			//	- solution[solutionIndex2]
////		}
////
////		return 0;
//// }
//class ThreeSamplesWithOneExclusion
//{
//public:
//	// Les 6 fonctions membres sp�ciales du C++
//	ThreeSamplesWithOneExclusion() = default;														// default constructor
//	ThreeSamplesWithOneExclusion(ThreeSamplesWithOneExclusion const &) = default;					// copy constructor
//	ThreeSamplesWithOneExclusion(ThreeSamplesWithOneExclusion &&) = default;						// move constructor
//	ThreeSamplesWithOneExclusion& operator=(ThreeSamplesWithOneExclusion const &) = default;		// copy assignment operator
//	ThreeSamplesWithOneExclusion& operator=(ThreeSamplesWithOneExclusion &&) = default;				// move assignment operator
//	~ThreeSamplesWithOneExclusion() = default;														// destructor
//	// Un autre constructor
//	ThreeSamplesWithOneExclusion(size_t sourceSize);												// custom constructor
//
//	// La fonction 'prepare' r�alise l'initialisation des donn�es internes. 
//	// Elle doit obligatoirement �tre appel�e au moins une fois avant l'appel 
//	// de la fonction 'select'. 
//	// 
//	// Param�tres : 
//	//		- sourceSize	: la taille du vecteur � �chantillonner, >= 4
//	//		- retour		: indique si la pr�paration a r�ussie
//	bool prepare(size_t sourceSize);
//
//	// R�alise l'�chantionnage. La fonction 'prepare' doit �tre appel�e au 
//	// moins une fois avant l'appel de 'select'.
//	//
//	// Trois �chantillons sont s�lectionn�s. Les �chantillons sont 
//	// diff�rents les uns des autres et de celui pass� en param�tre.
//	// 
//	// Param�tres :
//	//		- excludeIndex	: l'index � exlure de l'�chantillonage
//	//		- sample0		: l'index du premier �chantillon identifi�
//	//		- sample1		: l'index du deuxi�me �chantillon identifi�
//	//		- sample2		: l'index du troisi�me �chantillon identifi�
//	//		- retour		: indique si la s�lection a r�ussie
//	bool select(size_t exludedIndex, size_t & sample0, size_t & sample1, size_t & sample2);
//
//private:
//	std::default_random_engine mEngine;
//	std::vector<size_t> mSource;
//};
//
//
//#endif // _THREE_SAMPLE_WITH_ONE_EXCLUSION_H_
