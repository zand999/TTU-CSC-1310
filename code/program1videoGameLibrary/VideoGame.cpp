#include "VideoGame.h"

VideoGame::VideoGame(Text *title, int year, Text *platform,Text *genre,Text *ageRating, int rating){
	this -> title = title;
	this -> platform = platform;
	this -> genre = genre;
	this -> ageRating = ageRating;
	this -> rating = rating;
	this -> year = year;
}

VideoGame::~VideoGame(){
	
	delete this -> title;
	delete this -> platform;
	delete this -> genre;
	delete this -> ageRating;
	cout << "VideoGame destructor: Released memory for title, platform, genre, & rating.\n";
}
void VideoGame::printVideoGameDetails(){

	cout << "Title: ";
	title -> displayText();
	cout << "\nPlatform: ";
	platform -> displayText();
	cout << "\nYear: " << year << endl;
	cout << "Genre: ";
	genre -> displayText();
	cout << "\nAge Rating: ";
	ageRating -> displayText();
	cout << "\nUser Rating: " << rating << endl;
}
void VideoGame::printVideoGameDetailsToFile(ofstream &file){

	file << title -> getText() << endl;

	file << platform -> getText() << endl;
	file << year << endl;

	file << genre -> getText() << endl;

	file << ageRating -> getText() << endl;
	file << rating;
}
Text* VideoGame::getVideoGameTitle(){

	return title;

}
