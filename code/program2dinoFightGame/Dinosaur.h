
#ifndef Dinosaur_H
#define Dinosaur_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Dinosaur{
	
	private:

		string name,discription;
		int hp, atk;

	public:

		//consturer to fill all data on createion
		Dinosaur(string name, string discription, int hp, int atk){

			this -> name = name;
			this -> discription = discription;
			this -> hp = hp;
			this -> atk = atk;

		}
		//default constructor for dinosaur class
		Dinosaur(){};

		//defualt deconstor for dinosuar class
		~Dinosaur(){};

		//return the name varaible
		string getName(){
			return name;
		}

		//return the discription variable
		string getDiscription(){
			return discription;
		}

		//return the health varaible
		int getHP(){
			return hp;
		}

		//return the attack variable
		int getATK(){
			return atk;
		}

		//set the name variable
		void setName(string name){
			this -> name = name;
		}

		//set the discription variable
		void setDiscription(string discription){
			this -> discription = discription;
		}

		//set the the health varible
		void setHP(int hp){
			this -> hp = hp;
		}

		//set attack varaible
		void setATK(int atk){
			this -> atk = atk;
		}
		
		//print out data of dinosaur class with proper formating
		void printDino(){
			cout << "\nName: " << name;
			cout << "\nDESCRIPTION:";

			int length = discription.size();
			//set temp to default value;

			string temp = "";

			//set "max" length of each line
			int charWrapMin = 50;
	
			//start loop for itteration through each character in the discription
			for(int i = 0; i < length; i++){
				
				if(discription.at(i) == ' '){
					//add character to temp
					temp += discription.at(i);
					//check if temp size is larger than "max" line value
					if(temp.size() > charWrapMin){
						//if so return line and tab
						cout << temp << "\n\t";
						//reset value to start constructing new line
						temp = "";
					}
				}else{
					//if not just add the character to temp
					temp += discription.at(i);
				}
			}

			cout << "\nLIFE POINTS: " << hp;
			cout << "\nATTACK POINTS: " << atk;

		}


};

#endif