
#include <iostream>
using namespace std;

const int SIZE = 15;

void sort(string arr[]);
void print(string arr[]);
bool binarySearch(string arr[], string userCountry);
bool linearSearch(string arr[], string userCountry);

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
	if(linearSearch(countries, userCountry))
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
	if(binarySearch(countries, userCountry))
		cout << "does";
	else
		cout << "does not";
	cout << " have a confirmed case of the Coronavirus.\n";
	

	return 0;
}

bool linearSearch(string arr[], string userCountry)
{
	bool foundString = false;
	for(int x=0; x< SIZE; x++)
	{
		if(arr[x] == userCountry)
			return true;
	}
	return false;
}

bool binarySearch(string arr[], string userCountry)
{
	int beg = 0;
	int end = SIZE-1;
	bool found = false;
	while(beg <= end && !found)
	{
		int middle = (beg+end)/2;
		if(userCountry == arr[middle])
			found = true;
		else if(userCountry < arr[middle])
			end = middle-1;
		else
			beg = middle+1;
	}
	return found;
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

void print(string arr[])
{
	cout << "\nSorted list of countries:\n";
	for(int x=0; x < SIZE; x++)
	{
		cout << arr[x] << "\n";
	}
	cout << endl;
}




