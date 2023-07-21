#include "Song.h"
#include "Timer.h"
#include <iostream>
#include <fstream>
using namespace std;



//LOOK!!  ENTER YOUR FUNCTION PROTOTYPES HERE
void insertionSort(Song* array, int size);
void reverseBubbleSort(Song* array, int size);

void quickSort(Song *arr, int low, int high);
int partition(Song *arr, int left, int right);

int main()
{
	Song *mySongArray;
	mySongArray = new Song[150000];
	int numSongs = 0;
	float length;
	string temp;
	
	ofstream outFile;
	ifstream inFile;

	time_t start, end;
	char filename[50];
	cout << "\n\nWhat is the name of the file with songs? (example.txt)\n";
	cin >> filename;
	inFile.open(filename);
	
	if(!inFile)
	{
		cout << "\n\nSorry, I can't open the file songs.txt\n\n";
		exit(1);
	}
	
	while(getline(inFile, temp) && numSongs != 150000)
	{
		mySongArray[numSongs].setTitle(temp);
		getline(inFile, temp);
		mySongArray[numSongs].setArtist(temp);
		inFile >> length;
		inFile.ignore();
		mySongArray[numSongs].setLength(length);
		numSongs++;
	}
	cout << "\n\nYou have created " << numSongs << " Song objects.\n\n";
	
	
	
	//sort the songs using insertion sort and print them out to the text file sortFileInsertion.txt
	start = getTime(); //Starts timer.   
	
	//LOOK!!!!  CALL THE INSERTION SORT ALGORITHM HERE
	insertionSort(mySongArray, numSongs);
	
	end = getTime(); //Ends timer.
	outFile.open("sortFileInsertion.txt");
	cout << "\nInsertion sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	
	//sort the songs in reverse order using bubble sort & print them out to the text file sortFileReverseBubble.txt
	start = getTime(); //Starts timer. 
	
	//LOOK!!!!  CALL THE REVERSE BUBBLE SORT ALGORITHM HERE
	reverseBubbleSort(mySongArray, numSongs);
	
	end = getTime(); //Ends timer.
	outFile.open("sortFileReverseBubble.txt");
	cout << "\nReverse bubble sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	
	//sort the songs with quick sort & print them out to sortFileQuick.txt
	start = getTime(); //Starts timer. 

	
	//LOOK!!!!  CALL THE QUICKSORT ALGORITHM HERE
	quickSort(mySongArray,0,numSongs-1);
	
	
	end = getTime(); //Ends timer.
	cout << "\nQuicksort: " << totalTime(start, end) << " seconds\n\n";
	outFile.open("sortFileQuick.txt");
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	delete [] mySongArray;
	return 0;
}

//LOOK!  WRITE YOUR INSERTION SORT FUNCTION HERE
void insertionSort(Song* array, int size)
{
	Song key;
	int position;
	
	for(int i = 0; i < size; i++)
	{
		key = array[i];
		position = i - 1;
		while(position >= 0 && array[position].getTitle().compare(key.getTitle()) > 0)
		{
			array[position + 1] = array[position];
			position--;
		}
		array[position + 1] = key;
	}
}


//LOOK!  WRITE YOUR REVERSE BUBBLE SORT FUNCTION HERE
void reverseBubbleSort(Song* array, int size)
{
	Song temp;
	
	for(int i = size - 1; i > 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			if(array[j].getTitle().compare(array[j + 1].getTitle()) < 0)
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}




//LOOK!  WRITE YOUR RECURSIVE QUICK SORT FUNCTION HERE



//LOOK!  WRITE YOUR PARTITION FUNCTION HERE
void quickSort(Song *arr, int low, int high) 
{
	int pivot_location = 0;

	/* Base case: If there are 1 or zero elements to sort,
	partition is already sorted */
	if (low >= high) {
		return;
	}

	/* Partition the data within the array. */
	pivot_location = partition(arr, low, high); //returns location of last element in low partition
	quickSort(arr, low, pivot_location); //recursively sort low partition
	quickSort(arr, pivot_location + 1, high); //recursively sort high partition
}


int partition(Song *arr, int left, int right) {

   int  middle;
   string temp,pivot;
   bool done = false;
   
   //pivot starts at middle
   middle = left + (right-left) / 2;
   pivot = arr[middle].getTitle();
   int l = left;
   int r = right;
   while(!done)
   {
		while(arr[l].getTitle() < pivot) //increment l while arr[l] < pivot
		   ++l;
		while(pivot < arr[r].getTitle())//decrement r while pivot < arr[r]
		   --r;
		
		//if there are 0 or 1 elements remaining, all numbers are partiioned.  return r
		if(l >= r)
			done = true;
		else
		{
			//swap & update l and r
			temp = arr[l].getTitle();
			arr[l].setTitle( arr[r].getTitle());
			arr[r].setTitle(temp);
			++l;
			--r;
		}
   }
   return r;   
}