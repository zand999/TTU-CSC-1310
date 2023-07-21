
#ifndef _CLASSNAME_H
#define _CLASSNAME_H

#include <iostream>
#include <iomanip>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <sstream>

//#include "HashTable.h"
#include "HashEntry.h"


using namespace std;


class Cat{

	private:
		int idNum;
		string catName;
		string furColor;

	public:

		Cat(string name,string color);
		Cat(int id,string name,string color);
		Cat();
		void setID(int id);
		void setName(string name);
		void setColor(string color);
		int getID();
		string getName();
		string getColor();
		friend ostream& operator<<(ostream& os, Cat& a);
		
};


#endif