/*
  Title: prog5.cpp
  Author: Alex Zandstra
  Date Started: 11-20-2019
  Purpose: header file
*/


#ifndef _VIDEOGAME_H
#define _VIDEOGAME_H

#include <iostream>
#include <iomanip>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <sstream>
#include "Text.h"

using namespace std;


class VideoGame{

	private:
		int year, rating;
		Text *title;
		Text *platform;
		Text *genre;
		Text *ageRating;


	public:
		//constructor to create a new video game object
		VideoGame(Text *title, int year, Text *platform,Text *genre,Text *ageRating, int rating);
		//deconstructor to delete video game data
		~VideoGame();
		//print the data of video game
		void printVideoGameDetails();
		//save the data of video game to file
		void printVideoGameDetailsToFile(ofstream &file);
		//return the title of the video game
		Text* getVideoGameTitle ();
};



#endif