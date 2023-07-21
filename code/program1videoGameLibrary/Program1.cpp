/*
  Title: Program1.cpp
  Author: Alex Zandstra
  Date Started: 02/05/2020
  Purpose: Driver Program for Video Game Library
*/


#include "Text.h"
#include "VideoGame.h"
#include "VideoGameLibrary.h"

using namespace std;


int main(){

	int input;
	char textInput[1000] = {'\0'};

	cout << "How many video games can your library hold?\n";
	cin >> input;
	//dynamically create new VideoGameLibrary
	VideoGameLibrary *library = new VideoGameLibrary(input);
	cout << "\n";
	//reset input value
	input = -1;
	while(input != 6){

		//print menue
		cout << "\n-----------------------------\n";
		cout << "What would you like to do?\n";
		cout << "1. Load video games from file.\n";
		cout << "2. Save video games to a file.\n";
		cout << "3. Add a video game.\n";
		cout << "4. Remove a video game.\n";
		cout << "5. Display all video games.\n";
		cout << "6. Remove ALL video games from this library and end program.\n";
		cout << "CHOOSE 1-6: ";
		cin >> input;
		cout << "\n";

		while(input < 1 && input > 6 || cin.fail()){

			cout << "Please enter a valid input\n";
			cin.ignore(256,'\n');
			cin >> input;

			
		}
		

		
		//switch between menue selections
		switch(input){

			case 1:
				//Get name of text file
				cout << "What is the name of the text file you wish to write to?\nFilename: ";
				cin.ignore();
				gets(textInput);
				//pass filename to library
				library -> loadVideoGamesFromFile(textInput);

				break;
			case 2:
				//Get name of text file
				cout << "What is the name of the text file you wish to write to?\nFilename: ";
				cin.ignore();
				gets(textInput);
				//pass filename to library
				library -> saveToFile(textInput);
				break;
			case 3:
				library -> addVideoGameToArray();
				break;
			case 4:
				library -> removeVideoGameFromArray();
				break;
			case 5:
				library -> displayVideoGames();
				break;
			case 6:
				delete library;
				break;

		}

	}


}