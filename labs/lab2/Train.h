// Specification file for the ContactInfo class.
#ifndef CONTACTINFO_H
#define CONTACTINFO_H

#include <cstring>	// Needed for strlen and strcpy
#include <iostream>
using namespace std;

template<typename temp>
class Train{

	private:

		string name,home;
		int capacity,currPass;
		temp *seats;

	public:

		Train(string name, string home, int capacity){

			this -> name = name;
			this -> home = home;
			this -> capacity = capacity;
			currPass = 0;
			seats = new temp[capacity];


		}
		~Train(){

			delete[] seats;

		}

		string getTrainName(){
			return this -> name;
		}

		void addPassenger(temp a){

			if(currPass == capacity){
				cout << "No More passagers can get on\n";
			}else{
				seats[currPass] = a;
				currPass++;
			}

		}

		void printPassengers(){
			for(int i = 0; i < currPass; i++){

				cout << *seats[i] << endl;


			}


		}



};



#endif