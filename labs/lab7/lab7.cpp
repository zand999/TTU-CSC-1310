
#include <iostream>
#include <iomanip>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void quickSort(vector<int>& data, int low, int high);
int partition(vector<int>& data, int left, int right);
void getStudentData(vector<int>& data);
void print(vector<int>& data);
double getAverage(vector<int>& data);
double getMedian(vector<int>& data);
int getMode(vector<int>& data);

int main(){

	 vector<int> data;
	 getStudentData(data);
	
	 cout << "\nSorting the vetor with quick sort\n";
	 
	 quickSort(data, 0, data.size() - 1);
	 print(data);
	 cout << "\n\tNETFLIX STATISTICS\n";
	 cout << setprecision(2) << fixed;
	 cout << "Average: " << getAverage(data);
	 cout << "\nMedian: " << getMedian(data);
	 int mode = getMode(data);
	 cout << "\nMode: " << ((mode == -1)? "There is no mode." : to_string(mode));

}

void print(vector<int>& data){
	cout << "\nHours each student watache Netflox in acending order:";
	for(int i = 0; i < data.size(); i++){
	 	cout << " " << data[i];
	}
}

double getAverage(vector<int>& data){
	double sum = 0;
	for(int i = 0; i < data.size(); i++){
	 	sum += data[i];
	}
	return sum / data.size();

}
double getMedian(vector<int>& data){
	int size = data.size();
	if(size % 2 == 0){
		return (static_cast<double>(data[(size / 2) - 1]) + static_cast<double>(data[size / 2]))/2;

	}else{
		return static_cast<double>(data[(size / 2)]);
	}
	return 0;

}
int getMode(vector<int>& data){
	
	
	int num = -1,numTimesHighest = 0,currCount = 0;
	for(int i = 0; i < data.size() - 1;i++){
		if(data[i] == data[i+1]){
			currCount++;
			if(currCount > numTimesHighest){
				numTimesHighest = currCount;
				num = data[i];
			}
		}else{
			currCount = 0;
		}
	}
	return num;


}

void getStudentData(vector<int>& data){

	int input = 0,num = 1;
	cout << "\nEnter the number of hours each student spent watching Netflix.\n";
	cout << "\nEnter -1 when you are finished entering student data.\n";


	for(int i = 1; input >= 0; i++){
		cout << "Student " << i << ": ";
		cin >> input;
		data.push_back(input);
	}
	data.pop_back();

}

void quickSort(vector<int>& data, int low, int high){
	int pivot_location = 0;

	/* Base case: If there are 1 or zero elements to sort,
	partition is already sorted */
	if (low >= high) {
		return;
	}

	/* Partition the data within the array. */
	pivot_location = partition(data, low, high); //returns location of last element in low partition
	quickSort(data, low, pivot_location); //recursively sort low partition
	quickSort(data, pivot_location + 1, high); //recursively sort high partition
}

int partition(vector<int>& data, int left, int right) {

   int  middle;
   int temp,pivot;
   bool done = false;
   
   //pivot starts at middle
   middle = left + (right-left) / 2;
   pivot = data[middle];
   int l = left;
   int r = right;
   while(!done)
   {
		while(data[l] < pivot) //increment l while arr[l] < pivot
		   ++l;
		while(pivot < data[r])//decrement r while pivot < arr[r]
		   --r;
		
		//if there are 0 or 1 elements remaining, all numbers are partiioned.  return r
		if(l >= r)
			done = true;
		else
		{
			//swap & update l and r
			temp = data[l];
			data[l] = data[r];
			data[r] = temp;
			++l;
			--r;
		}
   }
   return r;   
}