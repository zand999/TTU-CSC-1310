
#include <iostream>
#include <iomanip>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "Stack.h"

int main(){

	//dynamicaly alocate stack of chars
	Stack<char> *list =  new Stack<char>;

	char temp;

	fstream file;

	file.open("file1.txt");

	//take in individual chars from file add them to the top of the stack
	if(file.is_open()){

		while(!file.eof()){
			
			file.get(temp);
			list -> push(temp);


		}
	}


	ofstream out;
	out.open("file2.txt");
	list -> pop(temp);

	//print out data to new file from top of stack
	if(out.is_open()){

		while(!(list -> isEmpty())){
			
			list -> pop(temp);
			out << temp;
			
		}

	}
	out.close();
	
}












