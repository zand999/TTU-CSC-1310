#ifndef PLANET_H
#define PLANET_H

#include <iostream>
using namespace std;

/*
	Title:  Planet.h
	Author: Alex Zandstra
	Date:  2-2-2020
	Purpose: Planet Class
*/


class Planet
{
	private:
		double minSurfaceTemp;
		double maxSurfaceTemp;
		double radius;
		
	public:
		//CONSTRUCTOR
		Planet()
		{
			minSurfaceTemp = 0.0;
			maxSurfaceTemp = 0.0;
			radius = 0.0;
			cout << "\nCreating a Planet!\n";
		}

		Planet(double size){
			cout << "Creating a Planet!\n";
			this -> minSurfaceTemp = 0;
			this -> maxSurfaceTemp = 0;
			this -> radius = size;
		}; 
		
		//DESTRUCTOR
		~Planet()
		{
			//cout << "\nDestroying a Planet!\n";
		}
	
		//ACCESSOR FUNCTIONS
		double getMinSurfaceTemp() const;
		double getMaxSurfaceTemp() const;
		double getRadius() const;
		
		//MUTATOR FUNCTIONS
		void setMinSurfaceTemp(double min);
		void setMaxSurfaceTemp(double max);
		void setRadius(double r);
		
		friend ostream & operator << (ostream& os, const Planet& a){
			os << "Min Surface Temp:  " << a.getMinSurfaceTemp() << "\nMax Surface Temp:  " << a.getMaxSurfaceTemp() << "\nRadius: " << a.getRadius();
			return os;
		};
		friend Planet operator + (const Planet& a, const Planet& b){
			
			return Planet(a.getRadius() + b.getRadius());
		};

};


#endif