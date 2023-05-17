//#pragma once
//#ifndef _THREE_SAMPLE_WITH_ONE_EXCLUSION_H_
//#define _THREE_SAMPLE_WITH_ONE_EXCLUSION_H_
//
//
//#include <vector>
//#include <random>
//
//
//// Génère trois échantillons distincts. Les indexes sélectionnés sont 
//// différents les uns des autres et différents de l'exclusion indiquée.
//// 
//// Cette classe est un exemple réalisant l'encapsulation d'un algorithme 
//// dédié (aucunement générique).*** 
//// 
//// L'algorithme se déroule en deux étapes pour des considérations de 
//// performance dans un contexte où plusieurs échantillonnages avec la même 
//// source de données sont réalisés.
////
//// La classe utilise les indexes à titre de référent. Autrement dit, elle 
//// n'utilise pas de pointeurs, de références ou d'itérateurs. La classe 
//// est indépendante du tableau source.
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
//	// Les 6 fonctions membres spéciales du C++
//	ThreeSamplesWithOneExclusion() = default;														// default constructor
//	ThreeSamplesWithOneExclusion(ThreeSamplesWithOneExclusion const &) = default;					// copy constructor
//	ThreeSamplesWithOneExclusion(ThreeSamplesWithOneExclusion &&) = default;						// move constructor
//	ThreeSamplesWithOneExclusion& operator=(ThreeSamplesWithOneExclusion const &) = default;		// copy assignment operator
//	ThreeSamplesWithOneExclusion& operator=(ThreeSamplesWithOneExclusion &&) = default;				// move assignment operator
//	~ThreeSamplesWithOneExclusion() = default;														// destructor
//	// Un autre constructor
//	ThreeSamplesWithOneExclusion(size_t sourceSize);												// custom constructor
//
//	// La fonction 'prepare' réalise l'initialisation des données internes. 
//	// Elle doit obligatoirement être appelée au moins une fois avant l'appel 
//	// de la fonction 'select'. 
//	// 
//	// Paramètres : 
//	//		- sourceSize	: la taille du vecteur à échantillonner, >= 4
//	//		- retour		: indique si la préparation a réussie
//	bool prepare(size_t sourceSize);
//
//	// Réalise l'échantionnage. La fonction 'prepare' doit être appelée au 
//	// moins une fois avant l'appel de 'select'.
//	//
//	// Trois échantillons sont sélectionnés. Les échantillons sont 
//	// différents les uns des autres et de celui passé en paramètre.
//	// 
//	// Paramètres :
//	//		- excludeIndex	: l'index à exlure de l'échantillonage
//	//		- sample0		: l'index du premier échantillon identifié
//	//		- sample1		: l'index du deuxième échantillon identifié
//	//		- sample2		: l'index du troisième échantillon identifié
//	//		- retour		: indique si la sélection a réussie
//	bool select(size_t exludedIndex, size_t & sample0, size_t & sample1, size_t & sample2);
//
//private:
//	std::default_random_engine mEngine;
//	std::vector<size_t> mSource;
//};
//
//
//#endif // _THREE_SAMPLE_WITH_ONE_EXCLUSION_H_
