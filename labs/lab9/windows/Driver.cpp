
#include <iostream>
#include <iomanip>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <sstream>
#include "GraphList.h"


using namespace std;



int main(){

	ifstream file;
	file.open("graph.txt");
	int input,input2;
	GraphList *graph;

	if(file.is_open()){
		file >> input;
		cout << "\nThere are " << input << " vertices in the graph\n\n";
		graph = new GraphList(input);
		
		while(!file.eof()){
			file >> input;
			file >> input2;
			cout << "Adding and edge from " << input << " to " << input2 << ".\n";

			graph -> addEdge(input, input2);


		}
	}else{
		cout << "\nERROR OPENING FILE! DOES \"graph.txt\" EXIST?\n";
	}
	file.close();

	graph -> printGraph();

	delete graph;

}