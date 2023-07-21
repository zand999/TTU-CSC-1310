
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

void displayArray(int*, int);
void changeToChar(int*,int);
void mergeSort(int*, int);
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
	mergeSort(myArr,n);

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
/*
void mergeSort(int *array, int size){
	int temp;
	if(size > 2){
		int size2 = size / 2, size1 = size - size2;
		int array1[size1], array2[size2];

		for(int i = 0; i < size1; i++){
			array1[i] = array[i];
		}
		for(int i = 0; i < size2; i++){
			array2[i] = array[size1 + i];
		}


		mergeSort(array1, size1);
		mergeSort(array2, size2);

		for(int i =0,j =0,k=0; i < size; i++){
			if(j < size1 && k < size2){
				if(array1[j] <= array2[k]){
					array[i] = array1[j];
					j++;
				}else{
					array[i] = array2[k];
					k++;
				}
			}else if(j < size1){
				array[i] = array1[j];
				j++;

			}else if(k < size2){
				array[i] = array2[k];
					k++;
			}
		}
	}

	if(size == 1){
		return;
	}else if(size ==2){
		if(array[0] > array[1]){
			swapping(array[0], array[1]);
		}
		return;
	}

	return;
}
*/

void mergeSort(int *array, int size){
	int temp;
	if(size > 1){
		int size2 = size / 2, size1 = size - size2;
		int array1[size1], array2[size2];

		for(int i = 0; i < size1; i++){
			array1[i] = array[i];
		}
		for(int i = 0; i < size2; i++){
			array2[i] = array[size1 + i];
		}


		mergeSort(array1, size1);
		mergeSort(array2, size2);

		for(int i =0,j =0,k=0; i < size; i++){
			if(j < size1 && k < size2){
				if(array1[j] <= array2[k]){
					array[i] = array1[j];
					j++;
				}else{
					array[i] = array2[k];
					k++;
				}
			}else if(j < size1){
				array[i] = array1[j];
				j++;

			}else if(k < size2){
				array[i] = array2[k];
					k++;
			}
		}
	}

	if(size == 1){
		return;
	}

	return;
}
