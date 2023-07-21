/*
	Purpose:	In-class Practice for sorting
*/
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

void displayArray(int*, int);
void changeToChar(int*,int);
void bubbleSort(int*, int);
void swapping(int &, int &);
void display(int *, int );

int main()
{	

	string plainText;
	int i;
    cout << "\n\nEnter a string of characters: ";
    getline(cin, plainText);
	
	int n=plainText.size();
	int myArr[n];
    int originalArray[n];
	
    for ( i = 0; i < n; i++) 
	{
		myArr[i] = static_cast<int>(plainText[i]);
    }
    cout << "\n\n#################################################";
	//display the array
	cout << "\n\nArray before changing to ASCII values: " << plainText << endl;
    cout << "ASCII Array before Sorting: ";
	displayArray(myArr,n);
	
	//sort the array
			/********CALL APPROPRIATE SORT FUNCTION HERE*********/


	bubbleSort(myArr, n);

	//display the array
    cout << "\n\nASCII Array after Sorting: ";
	displayArray(myArr,n);
	changeToChar(myArr,n);
	cout << "\n#################################################";
	cout << endl << endl;

	return 0;
}

void displayArray(int *arr, int size)
{
	for(int i=0; i<size; i++)
	{	
		cout << arr[i]<< " ";
	}
}

void changeToChar(int *r,int n) 
{
   int i;
   char s[n];
   cout<<"\n\nThe sorted string is = ";
   for ( i = 0; i < n; i++) 
   {
	   s[i]=static_cast<char>(r[i]);
       cout<<s[i];
   }
   cout<<"\n"; 
}

void swapping(int &a, int &b) {     //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}

void bubbleSort(int *array, int size){

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size - 1; j++){
			
			if(array[j] > array[j +1]){
				swapping(array[j], array[j+1]);

			}
		}
	}
	 

}










