
#include <iostream>
#include <iomanip>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <sstream>
#include "HashTable.h"
#include "HashEntry.h"
#include "Classname.h"


using namespace std;


void importFromFile(HashTable<Cat*> *temp);
void manualAdd(HashTable<Cat*> *temp);
void searchData(HashTable<Cat*> *temp);
void deleteData(HashTable<Cat*> *temp);

int main(){
	HashTable<Cat*> *catTable = new HashTable<Cat*>(10);
	int select = -1;

	while(select != 6){



		cout << "\nCat Management Menu\n\n";
		cout << "1. Add Cats From File\n";
		cout << "2. Add Cat Manually\n";
		cout << "3. Search for Cat\n";
		cout << "4. Delete a Cat\n";
		cout << "5. Print Hash Table\n";
		cout << "6. End Program\n";
		cout << "\nCHOOSE 1-6: ";
		cin >> select;
		
		//validate and select
		switch(select){
			case 1: 
				importFromFile(catTable);
				break;
			case 2:
				manualAdd(catTable);
				break;
			case 3:
				searchData(catTable);
				break;
			case 4:
				deleteData(catTable);
				break;
			case 5:
				catTable -> printHashTable();
				break;
			case 6:
				delete[] catTable;
				break;
			default:
				cout << "\nINVALID INPUT!\n";
				cin.clear();
    			cin.ignore(265,'\n');
				break;

		}


	}



	return 0;
}

void importFromFile(HashTable<Cat*> *temp){

	ifstream file;
	int key;
	string name,color;
	

	file.open("dataFile.txt");

	if(file.is_open()){
		Cat *input;
		while(!file.eof()){
			file >> key;
			file.ignore();
			getline(file,name);
			getline(file,color);
			cout << "Importing car with ID " << key << " and name " << name << ". \t";
			input = new Cat(key,name,color);
			temp -> putValue(key, input);



		}
	}else{
		cout << "\nERROR OPENING FILE! DOES \"dataFile.txt\" EXIST?\n";
	}
	file.close();

}
void manualAdd(HashTable<Cat*> *temp){

	
	int key;
	string name,color;
	cout << "KEY: ";
	cin >> key;
	while(key < 0 || cin.fail()){
    	cout << "Please enter a valid input.\nKEY: ";
    	cin.clear();
    	cin.ignore(265,'\n');
    	cin >> key;
  	}
	cin.ignore();
	cout << "CAT NAME: ";
	getline(cin,name);
	cout << "CAT COLOR: ";
	getline(cin,color);

	Cat *input = new Cat(key,name,color);



	temp -> putValue(key, input);

}
void searchData(HashTable<Cat*> *temp){

	int key;
	Cat *name;

	cout << "What is the key of the cat you are searching for?  ";
	cin >> key;
	name = temp -> getValue(key);
	if(name == NULL){
		cout << "NO CAT FOUND!\n";
	}else{
		cout << "\n----------------------------\n";
		cout << "ID: " << name -> getID() << "\n";
		cout << "Name: " << name -> getName() << "\n";
		cout << "Fur Color: " << name -> getColor() << "\n"; 
		cout << "----------------------------\n";
	}



}
void deleteData(HashTable<Cat*> *temp){

	int key;
	cout << "What is the key of the cat you wish to delete?  ";
	cin >> key;
	temp -> removeValue(key);

}




