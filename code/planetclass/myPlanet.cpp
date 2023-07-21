#include <iostream>
#include <string>
#include "planet.h"

using namespace std;

int main(){

	Planet unknown;
	int temp;

	cout << "Set Min SurfaceTemp: ";
	cin >> temp;
	unknown.setMinSurfaceTemp(temp);
	cout << "Set Max SurfaceTemp: ";
	cin >> temp;
	unknown.setMaxSurfaceTemp(temp);
	cout << "Set Size: ";
	cin >> temp;
	unknown.setSize(temp);

	cout << "Min Serface Temp: " << unknown.getMinSurfaceTemp() << endl;
	cout << "Max Serface Temp: " <<unknown.getMaxSurfaceTemp() << endl;
	cout << "Size: " <<unknown.getSize() << endl;



	return 0;




}




