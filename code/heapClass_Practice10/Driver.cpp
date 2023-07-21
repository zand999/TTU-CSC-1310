

#include <iostream>
#include <iomanip>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <sstream>

#include "minHeap.h"


int main(){
	

	MinHeap *heap = new MinHeap(4);
	heap -> insert("everyday");
	heap -> insert("do");
	heap -> insert("coding");
	heap -> insert("like");
 	heap -> insert("I");
 	cout << "Size: " << heap -> getSize() << "\nHeight: " << heap -> getHeight() << "\nRoot: " << heap -> peek() <<"\n";
 	int s = heap -> getSize();

 	for(int i = 0 ; i < s; i++){
 		cout << heap -> remove() << " "; 
 	}
 	cout << "\n";
 	heap -> insert("nonsense");
 	heap -> clear();
 	if(heap -> isEmpty()){
 		cout << "Heap has been cleared to the screen\n";
 	}

 	delete heap;

}