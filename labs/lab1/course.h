


#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <sstream>

using namespace std;

//structure for cost data
struct Course{

	string name;
	string location;
	string *list;
	int sections;
	int hours;

};

//create methods

Course* createCourse(string, string, int, int);
void destroyCourse(Course* myCourse);
void printCourse(Course* myCourse);
#endif