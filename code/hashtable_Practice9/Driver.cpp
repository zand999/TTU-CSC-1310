

#include <iostream>
#include <string>
#include "HashTable.h"
using namespace std;

int asciiadd(string value){

	int out = 0;
	for(int i = 0; i < value.length(); i++){

		out += int(value.at(i));
	}
	return out;
}



int main()
{
	int size;
	int key;
	string value;

	
	cout << "\nHello.\n\n";
	
	cout <<"What size is the table?   ";
	cin >> size;
	
	//create a Hash Table
	HashTable myHashTable(size);
	
	//add some keys and values
	cout << "\nEnter a value:  ";
	cin.ignore();
	getline(cin,value);
	key = asciiadd(value);
	cout << "Key is: " << key << "\n";
	myHashTable.putValue(key, value);
	
	cout << "\nEnter a value:  ";
	getline(cin,value);
	key = asciiadd(value);
	cout << "Key is: " << key << "\n";
	myHashTable.putValue(key, value);
	
	cout << "\nEnter a value:  ";
	getline(cin,value);
	key = asciiadd(value);
	cout << "Key is: " << key << "\n";
	myHashTable.putValue(key, value);
	
	cout << "\nEnter a value:  ";
	getline(cin,value);
	key = asciiadd(value);
	cout << "Key is: " << key << "\n";
	myHashTable.putValue(key, value);
	
	cout << "\n\nHERE IS THE TABLE:\n\n";
	myHashTable.printHashTable();
	cout << endl << endl;
	
	
	
}