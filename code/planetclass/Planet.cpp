#include "planet.h"


		
void Planet::setMinSurfaceTemp(int num){
	minimumSurfaceTemp = num;
}
void Planet::setMaxSurfaceTemp(int num){
	maximumSurfaceTemp = num;
}
void Planet::setSize(int num){
	size = num;
}
int Planet::getMinSurfaceTemp(){
	return minimumSurfaceTemp;
}
int Planet::getMaxSurfaceTemp(){
	return maximumSurfaceTemp;
}
int Planet::getSize(){
	return size;
}

