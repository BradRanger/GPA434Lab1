
#include <vector>
#include <iostream>


//array est une reference vers un vecteur qui contient des int
//*doSomething = adresse dune fonction qui prend en parametre une reference vers un int
void browse(std::vector<int>& array, void(*doSomething)(int&)) {
	//on veut la reference de ces ints la qui vont se stocker tour a tour dans value
	//eperluette veut dire reference
	//me donne acces a la valeur
	// si on enleve & dans la boucle, on travaille seulement avec une copie qui sera supprimee a la fin de son scope
	//si on utilise eperluette, on modifie la valeur

	for (int& value : array) {
		//on peut utiliser nimportequelle fonction tant qu'elle ait le mm type de retour,
		//le meme type en argument et le meme nombre d'arguments et dans le bon ordre.
		//ex int char int
		doSomething(value);
	}
}

void display(int& value) { std::cout << value << " "; }
void square(int& value) { value *= value; }
void negate(int& value) { value = -value; }
void init(int& value) {

	//static fait en sorte que ma variable persiste a travers de mon programme
	//une autre fonction pourrait modifier la valeur de v, mais il faut que la fonction soit
	//appellee a linterieur de la fonction ou le static truc se trouve.

	static int v{}; //static keyword fait en sorte que la variable est instantiee 
	//seulement une fois. Elle est vivante tout le long du programme.
	//static ici permet de conserver(permanament) la valeur dune variable 
	//declaree a linterieur dune fonction.

	value = v++;
}



int main()
{
	std::vector<int> data(7);

	browse(data, init);
	browse(data, display);
	std::cout << "\n";

	browse(data, square);
	browse(data, display);
	std::cout << "\n";

	browse(data, negate);
	browse(data, display);
	std::cout << "\n";

	return 0;

}