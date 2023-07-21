/*
  Title: Program1.cpp
  Author: Alex Zandstra
  Date Started: 02/05/2020
  Purpose: Driver Program for Video Game Library
*/


#include "Text.h"
#include "VideoGame.h"
#include "VideoGameLibrary.h"

int main(){

	//char text[100] = {'b','o','b',' ','i','s',' ','h','e','r','e','\0'};
	/*Text test("test");
	test.displayText();

	const char *teststring = test.getText();

	cout << "\nText: " << teststring;
	cout << "\nSize: " << test.getLength();

	*/


	/*Text *title = new Text("Title1");
	int year = 2001;
	Text *platform = new Text("platform1");
	Text *genre = new Text("Genre1");
	Text *ageRating = new Text("ageRating1");
	int rating = 100;

	VideoGame *test = new VideoGame(title,year,platform,genre,ageRating,rating);
	test->printVideoGameDetails();

	ofstream file;
	file.open("bob.txt");
	test -> printVideoGameDetailsToFile(file);
	//cout << "test thing " << (test -> getVideoGameTitle()) -> getText();
	cout << "test thing \n";
	test -> getVideoGameTitle() -> displayText();
	*/

	//int 

	return 0;

}
//VideoGame::VideoGame(Text *title, int year, Text *platform,Text *genre,Text *ageRating, int rating){