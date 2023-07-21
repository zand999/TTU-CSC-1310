#ifndef PLANET_H
#define PLANET_H

#include <iostream>
using namespace std;

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
		
};


#endif