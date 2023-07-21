/*
	Driver for Course Structure
	LAB 1 - CSC1310
	Alex Zandstra
	
	1/10/2019
*/


#include <iostream>

using namespace std;

int arraySum(int[],int);

int main ()
{
	int size = 5;
	int array[5] = {4,7,2,7,3};
	cout << "Sum is: " << arraySum(array,size) << endl;
	
	return 0;
}

int arraySum(int array[],int length){

	length--;
	if(length >= 0){

		return arraySum(array,length) + array[length];
	}else{
		return 0;
	}


}