

#ifndef _GRAPHMATRIX_H
#define _GRAPHMATRIX_H

#include <iostream>
#include <iomanip>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <sstream>



using namespace std;


class GraphMatrix{

	private:
		int **vertexMatrix;
		int numVertices;
		int numEdges;

	public:

		GraphMatrix(int numVertices){

			vertexMatrix = new int*[numVertices];
			for(int i = 0; i < numVertices; i++){
				vertexMatrix[i] = new int[numVertices]{0};
			}
			this -> numVertices = numVertices;
			numEdges = 0;

		}
		GraphMatrix(){}

		~GraphMatrix(){

			for(int i = 0; i < numVertices; i++){

				delete[] vertexMatrix[i];
			}
			delete[] vertexMatrix;


		}
		void addEdge(int x, int y){
			if(!(isThereAnEdge(x,y))){
				vertexMatrix[x][y] = 1;
			}
		}

		void printGraph(){
			cout << "\nAdjacency Matrix:\n";

			for(int i = 0; i < numVertices; i++){

				for(int j = 0; j < numVertices; j++){
					cout << vertexMatrix[i][j] << " ";
				}
				cout << "\n";
			}

		}

		bool isThereAnEdge(int x, int y){
			return vertexMatrix[x][y];
		}

		int getFirstVertex(){
			bool isone = false;
			for(int i = 0; i < numVertices; i++){

				for(int j = 0; j < numVertices; j++){

					if(vertexMatrix[j][i] == 1){
						 isone = true;
						 break;
					}
				}
				if(!isone){
					return i;
				}
				isone = false;
				
			}
			return 0;
		}

		
};


#endif