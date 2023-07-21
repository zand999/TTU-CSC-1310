#include "linkedList.h"

using namespace std;
#include <iostream>
#include <string>

int main(){

	LinkedList<string> dogBreeds;

	dogBreeds.append("Corgi");
	dogBreeds.append("English Bulldog");
	dogBreeds.append("Dalmatian");
	dogBreeds.append("German Shepard");
	dogBreeds.append("Poodle");

	dogBreeds.displayList();

	cout << "\nGoodbye\n";




}



