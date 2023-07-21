#include "VideoGameLibrary.h"

VideoGameLibrary::VideoGameLibrary(int maxGames){

	this -> maxGames = maxGames;
	this -> videoGamesArray = new VideoGame*[maxGames];
	this -> numGames = 0;


}
VideoGameLibrary::~VideoGameLibrary(){
	delete[] videoGamesArray;
	cout << "\nVideoGameLibrary destructor: Released memory for each game in the video game array and the array itself.\n";
}
void VideoGameLibrary::resizeGameLibrary(){
	VideoGame **temp = new VideoGame*[maxGames];
	for(int i = 0; i < maxGames; i++){
		temp[i] = videoGamesArray[i];
	}
	videoGamesArray = new VideoGame*[maxGames * 2];
	for(int i = 0; i < maxGames; i++){
		videoGamesArray[i] = temp[i];
	}
	delete[] temp;
	maxGames *= 2;
}
void VideoGameLibrary::addVideoGameToArray(){

	char textInput[10000] = {'\0'};
	int year, rating;
	
	Text *title,*platform,*genre,*ageRating;
	cout << "\nPlease input game information\n";

	cin.ignore();
	cout << "\nTitle: ";
	gets(textInput);
	title = new Text(textInput);
	

	cout << "\nYear: ";
	cin >> year;

	cin.ignore();
	cout << "\nPlatforms: ";
	gets(textInput);
	platform = new Text(textInput);

	cout << "\nGenre: ";
	gets(textInput);
	genre = new Text(textInput);

	cout << "\nAge Rating: ";
	gets(textInput);
	ageRating = new Text(textInput);

	cout << "\nRating: ";
	cin >> rating;
	

	VideoGame *temp = new VideoGame(title,year,platform,genre,ageRating,rating);

	if(numGames == maxGames){
		resizeGameLibrary();
	}

	//videoGamesArray[numGames] = new VideoGame(title,year,platform,genre,ageRating,rating);

	videoGamesArray[numGames] = temp;
	
	numGames++;

}
void VideoGameLibrary::displayVideoGames(){

	
	for(int i = 0;i < numGames; i++){
		cout << "\n--------------Game " << (i +1) << "--------------\n";
		videoGamesArray[i]->printVideoGameDetails();
	}
	cout << "\n";
}
void VideoGameLibrary::displayVideoGameTitles(){

	cout << "\n--------------Titles--------------\n";
	for(int i = 0;i < numGames; i++){
		
		cout << i + 1 << ". ";
		videoGamesArray[i] -> getVideoGameTitle() -> displayText();
		cout << "\n";
	}
	cout << "\n";

	//(test -> getVideoGameTitle()) -> getText()

}
void VideoGameLibrary::loadVideoGamesFromFile(char *fileName){
	
	char textInput[10000];
	
	int numAdded = 0;

	ifstream file;
	file.open(fileName);
	if(file.is_open()){
    	//read first line to figure out array size
		while(!file.eof()){


			int year, rating;
			Text *title,*platform,*genre,*ageRating;
			
			file.getline(textInput, 10000, '\n');
			title = new Text(textInput);

			file.getline(textInput, 10000, '\n');
			platform = new Text(textInput);

			file >> year;

			file.ignore();
			file.getline(textInput, 10000, '\n');
			genre = new Text(textInput);

			file.getline(textInput, 10000, '\n');
			ageRating = new Text(textInput);

			file >> rating;

			VideoGame *temp = new VideoGame(title,year,platform,genre,ageRating,rating);

			if(numGames == maxGames){
				resizeGameLibrary();
			}

			videoGamesArray[numGames] = temp;
			//videoGamesArray[numGames] = new VideoGame(title,year,platform,genre,ageRating,rating)
			numGames++;

			
			file.ignore();

			numAdded++;

		}
      	
      	cout << "\n" << numGames << " games were added to the video game library!\n";
    	file.close();

    }else{
      cout << "Error opening file program failed\n";
    }



	file.close();
}
void VideoGameLibrary::saveToFile(char *fileName){

	ofstream file;
	file.open(fileName);
	if(file.is_open()){
		for(int i = 0; i < numGames; i++){
			videoGamesArray[i] -> printVideoGameDetailsToFile(file);
			if(i !=  numGames - 1){
				file << "\n";
			}
		}
	}
	file.close();
	cout << "\nLibrary successfully saved to " << fileName << "\n";

}
void VideoGameLibrary::removeVideoGameFromArray(){

	int input;
	if(numGames >= 1){

	 	displayVideoGameTitles();
	 	cout << "\nPlease enter game to delete: ";
	 	cin >> input;
	 	cout << "\n";
	 	videoGamesArray[input - 1] -> getVideoGameTitle() -> displayText();
	 	cout << " was successfully deleted!\n";
	 	delete videoGamesArray[input -1];
	 	for(int i = input - 1; i < numGames; i++){
	 		videoGamesArray[i] = videoGamesArray[i + 1];
	 	}
	 	numGames--;
	 	
	 }else{

	 	cout << "\nThere must always be one video game in the library.\n";

	 }
}