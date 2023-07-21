

#include <iostream>
#include <iomanip>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <sstream>
#include "Classname.h"
Cat::Cat(){
	idNum = -1;
	catName = "";
	furColor = "";
}
Cat::Cat(string name,string color){
	catName = name;
	furColor = color;
}
Cat::Cat(int id,string name,string color){
	idNum = id;
	catName = name;
	furColor = color;
}

void Cat::setID(int id){
	idNum = id;
}
void Cat::setName(string name){
	catName = name;
	
}
void Cat::setColor(string color){
	furColor = color;
}

int Cat::getID(){
	return idNum;
}
string Cat::getName(){
	return catName;
	
}
string Cat::getColor(){
	return furColor;
}
ostream& operator<<(ostream& os, Cat& a){
	os << "ID: " << a.getID() << " Name: " << a.getName();
	
	return os;
	
};
