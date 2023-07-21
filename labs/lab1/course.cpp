#include "course.h"

Course* createCourse(string name, string location, int sections, int hours){

	Course *temp = new Course;
	temp->name = name;
	temp->location = location;
	temp->sections = sections;
	temp->list = new string[sections];
	temp->hours = hours;

	return temp;
}
void destroyCourse(Course* myCourse){
	delete myCourse;
}
void printCourse(Course* myCourse){
	
	cout << "\nCourse Name:\t\t" << myCourse->name;
	cout << "\nCourse location:\t" << myCourse->location;
	cout << "\nCourse Hours:\t\t" << myCourse->hours;
	cout << "\nCourse Sections:\n";
	for(int i = 0; i < myCourse->hours; i++){



		cout << "\t\t\t" << myCourse->list[i] << endl;

	}

}