/*
  Title: graph.cpp
  Author: Alex Zandstra
  Date Started: 4-28-2020
  Purpose: driver file for Graph DFS
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <sstream>

//#include "HashTable.h"
#include "GraphMatrix.h"
#include "GraphList.h"
#include "Stack.h"

using namespace std;

int main(){

	GraphList *graphlist;
	GraphMatrix *graphmatrix;
	string name;
	int input,input2,size;

	cout << "Enter in the filename of your file that contains the graph verticies: ";
	cin >> name;
	ifstream file;
	file.open(name);

	if(file.is_open()){
		file >> size;
		cout << "\nThere are " << input << " vertices in the graph\n\n";
		graphlist = new GraphList(size);
		graphmatrix = new GraphMatrix(size);
		while(!file.eof()){
			
			file >> input;
			file >> input2;

			graphmatrix -> addEdge(input, input2);
			graphlist -> addEdge(input, input2);



		}

	}else{
		cout << "\nERROR OPENING FILE! DOES \"" << name << "\" EXIST?\n";
	}
	file.close();

	graphmatrix -> printGraph();
	graphlist -> printGraph();


	Stack <int>*stack = new Stack<int>();
	bool *visited = new bool[size]{0};
	stack -> push(graphmatrix -> getFirstVertex());
	int currentV;
	cout <<"\n\nNow traversing & printing graph vertices with DFS.\n\n";

	while(!(stack -> isEmpty())){
		stack -> pop(currentV);
		if(!(visited[currentV])){
			cout << currentV << "\t";
			visited[currentV] = true;
			for(int i = size - 1; i >= 0; i--){
				if(graphmatrix -> isThereAnEdge(currentV, i) && !(visited[i])){
					stack -> push(i);
				}
			}


		}

	}
	delete[] visited;



}