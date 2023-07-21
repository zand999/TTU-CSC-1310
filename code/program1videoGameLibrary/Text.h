/*
  Title: prog5.cpp
  Author: Alex Zandstra
  Date Started: 11-20-2019
  Purpose: header file
*/



#ifndef _TEXT_H
#define _TEXT_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cstring>


using namespace std;

class Text{

	private:
		int size;
		const char *string;

	public:
		//constructor to create c-string
		Text(const char *array);
		//deconstructor to delete c-string
		~Text();
		//print out c-string
		void displayText();
		//return c-string
		const char* getText();
		//return length of c-string
		int getLength();
};



#endif