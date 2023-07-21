
#include <iostream>
#include <iomanip>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "LinkedList.h"
#include "Dinosaur.h"


using namespace std;

bool binarySearch(LinkedList<Dinosaur> *dinos, int first, int last, string search);
void mergeSort(Dinosaur *array, int size);
Dinosaur dinoSelect(LinkedList<Dinosaur> *dinos, string);


int main(){

	//create linked list of dinos
	LinkedList<Dinosaur> *dinos =  new LinkedList<Dinosaur>;
	
	//declare varibles
	string name,discription,input = "y",name1,name2;
	int hp,atk;

	srand (time(NULL));
	Dinosaur temp,player1dino,player2dino;
	
	//declare instream
	ifstream file;

	//open file
	file.open("dinosaurFile.txt");

	//check if file is open
	if(file.is_open()){
    	

    	//start the importing in of dinos
		while(!file.eof()){

			//get file dino information
			getline(file,name);
			getline(file,discription);
			file >> hp;
			file >> atk;

			//set dino information to a temporay dinosaur
			temp = Dinosaur(name,discription,hp, atk);
			file.ignore();

			//check to see if it already exsts in the linked list with binary sort
			if(!(binarySearch(dinos,0,(dinos -> getLength()) -1, name))){
				
				//add dino to linked list
				dinos -> appendNode(temp);
				cout << dinos -> getNodeValue(dinos -> getLength() -1 ).getName() << " was added to the list of dinosaurs that can fight!\n";
				
				//create temporary array with same size of linked list
				Dinosaur *tempArray = new Dinosaur[dinos -> getLength()];
				int tempLength = dinos -> getLength();

				//make copy of data in linked list for the array
				for(int i = 0; i < tempLength; i++){
					tempArray[i] = dinos -> getNodeValue(i);
				}

				//sort the array
				mergeSort(tempArray,(dinos -> getLength())-1);

				//create new linked list
				dinos =  new LinkedList<Dinosaur>;
				
				//moved contents of array into linked list
				for(int i = 0; i < tempLength; i++){
					dinos -> appendNode(tempArray[i]);

				}
				
				//delete array
				delete[] tempArray;
			}
			

		}

		cout << "Added " << dinos -> getLength() << " dinosaurs.\n";


		
	}
	//close file
	file.close();

	//start game
	cout << "\nGAME IS READY!\n";
	while(input == "y"){

		
		//get names
		cout << "PLAYER 1 NAME: ";
		getline(cin,name1);

		cout << "PLAYER 2 NAME: ";
		getline(cin,name2);

		cout << "\nBefore you have to select your dinosaur. do you want to print details about each one?(y/n)\n";

		cin >> input;
		
		//print out dino information
		while(input != "y" && input != "n" ){
			cout << "please enter y or n\n";
			cin >> input;
		}
		if(input == "y"){
				cout << "******************************************************************\n";
			for(int i = 0; i < dinos -> getLength(); i++){
				
				cout << "DINOSAUR " << i +1  << "\n";
				dinos -> getNodeValue(i).printDino();
				cout << "\n*******************************************************************\n";
			}
			
		}


		//get player dino selection
		player1dino = dinoSelect(dinos, name1);
		player2dino = dinoSelect(dinos, name2);

		cin.ignore();

		//start turns
		for(int i = 0; i < 3; i++){


			cout << "\n****************************ROUNND " << i + 1 << "!******************************\n";

			//player one turn
			cout << name1 << " hit enter to roll the dice.\n";
			cin.ignore();
			int dieRoll = (rand() % 6) + 1;
			player2dino.setHP(player2dino.getHP() - (player1dino.getATK() * dieRoll));
			cout << "YOU HIT " << player2dino.getName() << " for " << player1dino.getATK() * dieRoll << " points!\n";
			cout << player2dino.getName() << " now has " << player2dino.getHP() << " health left.\n\n";

			//check if player one won
			if(player2dino.getHP() <= 0){
				cout << name1 << ", " << player1dino.getName() << "knocked out " << player2dino.getName() << "!\n";
				cout << name1 << " WON!\n";
				break;
			}

			//player two turn
			cout << name2 << " hit enter to roll the dice.\n";
			cin.ignore();
			dieRoll = (rand() % 6) + 1;
			player1dino.setHP(player1dino.getHP() - (player2dino.getATK() * dieRoll));
			cout << "YOU HIT " << player1dino.getName() << " for " << player2dino.getATK() * dieRoll << " points!\n";
			cout << player1dino.getName() << " now has " << player1dino.getHP() << " health left.\n\n";
			
			//check if player 2 won
			if(player1dino.getHP() <= 0){
				cout << name2 << ", " << player2dino.getName() << "knocked out " << player1dino.getName() << "!\n";
				cout << name2 << " WON!\n";
				break;
			}

			//check if all three turns have been taken
			if(i == 2){
				if(player1dino.getHP() == player2dino.getHP()){

					cout << "\nThe game was a tie with both dinos with " << player1dino.getHP() << " HP left.\n";
				}else if(player1dino.getHP() < player2dino.getHP()){

					cout << "\nPlayer " << player1dino.getHP() << " won with "<< player1dino.getHP() << "HP left.\n";
				}else if(player1dino.getHP() > player2dino.getHP()){

					cout << "\nPlayer " << player2dino.getHP() << " won with " << player2dino.getHP() << "HP left.\n";
				}
			}


		}


		//ask to play again and reset
		cout <<  "Would you like to play again?\n";
		cin >> input;
		while(input != "y" && input != "n" ){
			cout << "please enter y or n\n";
			cin >> input;
		}
		if(input == "n"){
			break;
		}
		cout << "\n*******************************************************************\n";
		cin.ignore();

	}
	cout << "\n\nGOODBYE!\n";

}

//binary search a dinos linked list with recursion
bool binarySearch(LinkedList<Dinosaur> *dinos, int first, int last, string search){

	if (first > last) //value was not found
		return false;

	int spot = (first + last) /2;
	if(dinos -> getLength() == 0){
		return false; 
	}
	
	if(dinos -> getNodeValue(spot).getName() == search){

		return true;

	}else if(dinos -> getNodeValue(spot).getName() < search){

		return binarySearch(dinos, spot+1,last,search);

	}else if(dinos -> getNodeValue(spot).getName() > search){

		return binarySearch(dinos, first,spot-1,search);

	}
	
	return false;

	

}

//merge sort a dinosaur array with recurrsion
void mergeSort(Dinosaur *array, int size){

	int temp;
	if(size > 1){
		int size2 = size / 2, size1 = size - size2;
		Dinosaur array1[size1], array2[size2];

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
				if(array1[j].getName() <= array2[k].getName()){
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
		
	}else if(size == 1){
		return;
	}
}

//get a player dino selection and return the dino data that was selected
Dinosaur dinoSelect(LinkedList<Dinosaur> *dinos, string name){

	Dinosaur out;
	int choice;
	cout << "\n" << name << ", ENTER THE DINOSAUR NUMBER YOU WISH TO FIGHT!\n";
	cout << "*******************************************************************\n";
	for(int i = 0,j=0; i < dinos -> getLength(); i++){
		cout << i + 1 << "-" << dinos -> getNodeValue(i).getName() << ((dinos -> getNodeValue(i).getName().length() < 8)? "\t\t" : "\t");
		j++;
		if(j == 4){
			cout << "\n";
			j = 0;
		}

	}
	cout << "\n*******************************************************************\n";

	cout << name << " choice 1-" << dinos -> getLength() << ": ";
	cin >> choice;
	while(choice < 1 && choice > dinos -> getLength()){
			cout << "please enter a number betwee 1 and " << dinos -> getLength() << ".\n";
			cin >> choice;
	}
	out = dinos -> getNodeValue(choice - 1);
	return out;


}
