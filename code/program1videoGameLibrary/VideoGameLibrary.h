/*
  Title: prog5.cpp
  Author: Alex Zandstra
  Date Started: 11-20-2019
  Purpose: header file
*/


#ifndef _VIDEOGAMELIBRARY_H
#define _VIDEOGAMELIBRARY_H

#include <iostream>
#include <iomanip>
#include <math.h>
/*
  Title: VideoGameLibrary.h
  Author: Alex Zandstra
  Date Started: 02/05/2020
  Purpose: Driver Program for Video Game Library
*/

#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <sstream>
#include <stdio.h>
#include "Text.h"
#include "VideoGame.h"

using namespace std;

class VideoGameLibrary{

	private:

		VideoGame **videoGamesArray;
		int maxGames,numGames;
	public:
		//constructor for VideoGameLibrary
		VideoGameLibrary(int maxGame);
		//Deconstructor
		~VideoGameLibrary();
		//double the size of the library
		void resizeGameLibrary();
		//Takes input to add a new video game to the library
		void addVideoGameToArray();
		//prints out all video game details
		void displayVideoGames();
		//prints out all video game titles
		void displayVideoGameTitles();
		//takes in file name and adds the data to video game 
		void loadVideoGamesFromFile(char *fileName);
		//takes in file name and saves the video game data to it
		void saveToFile(char *fileName);
		//deletes a videogame from the library and moves rest of data up 1
		void removeVideoGameFromArray();


};


#endif