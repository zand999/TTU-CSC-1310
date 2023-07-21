
#include <iostream>
using namespace std;

const int SIZE = 15;

void sort(string arr[]);
void print(string arr[]);

//add prototype for linear search function
bool linearSearch(string list[], string search);
//add prototype for binary search function
bool binarySearch(string list[], int first, int last, string search);

int main()
{
	string userCountry;

	string countries[SIZE] = 
		{
			"China",
			"Hong Kong", 
			"Australia",
			"Canada",
			"Finland",
			"France",
			"Germany",
			"India",
			"Italy",
			"Japan",
			"Spain",
			"Sweden",
			"Thailand",
			"United Kingdom",
			"United States"
		};
		
	cout << "\nWhat is the name of your country?  ";
	getline(cin, userCountry);
	
	//linear search
	cout << "\nLinear Search says that your country ";
	if(linearSearch(countries,userCountry))
		cout << "does";
	else
		cout << "does not";
	cout << " have a confirmed case of the Coronavirus.\n";
	
	//sort is necessary for binary search
	sort(countries);
	
	//print to make sure it is sorted
	print(countries);
	
	//binary search
	cout << "\nBinary Search says that your country ";
	if(binarySearch(countries,0,SIZE,userCountry))
		cout << "does";
	else
		cout << "does not";
	cout << " have a confirmed case of the Coronavirus.\n";
	
	return 0;
}

//a simple function to sort array elements in ascending order
void sort(string arr[])
{
	string key; 
	int j;  
	
	for(int i=1; i < SIZE; i++)
	{
		key = arr[i]; 
		j = i-1; 
		while(j >= 0 && arr[j] > key) 
		{
			arr[j+1] = arr[j]; 
			j = j-1; 
		}
		arr[j+1] = key;
	}
}

//print array elements
void print(string arr[])
{
	cout << "\nSorted list of countries:\n";
	for(int x=0; x < SIZE; x++)
	{
		cout << arr[x] << "\n";
	}
	cout << endl;
}


//linear search function
bool linearSearch(string list[], string search){

	bool out = false;
	for(int i = 0;i < SIZE && !out ; i++)
		if(list[i] == search)
			out = true;
	return out;
}
//binary search function
bool binarySearch(string list[], int first, int last, string search){

	if (first > last) //value was not found
		return false;

	int spot = (first + last) /2;
	if(list[spot] == search){
		return true;
	}else if(list[spot] < search){
		return binarySearch(list, spot+1,last,search);
	}else if(list[spot] > search){
		return binarySearch(list, first,spot-1,search);
	}



}
























