#include "Text.h"
Text::Text(const char *array){
			

	size = strlen(array);
	
	char* tempTextArray = new char[(size)+1];
	
	
	strcpy(tempTextArray, array); 
	
	
	string = tempTextArray;	
	
}

Text::~Text(){
	
	cout << "Text destructor: Released memory for textArray.\n";
	delete[] string;
}
void Text::displayText(){
	for(int i=0;i < size;i++)
		cout << string[i];
}
const char* Text::getText(){
	return string;
}

int Text::getLength(){

	return size;
}