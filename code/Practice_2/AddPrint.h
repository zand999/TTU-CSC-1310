
#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <iostream>
#include <iostream>
#include <iomanip>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <sstream>
using namespace std;


/*
	Title:  AddPrint.h
	Author: Alex Zandstra
	Date:  2-2-2020
	Purpose: AddPrint class
*/

template<typename temp>
class AddPrint{
public:
	temp add(temp a, temp b){
		return a + b;
	};
	void print(temp a){
		cout << a << endl;
	};


};
#endif