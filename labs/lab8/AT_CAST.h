


#ifndef _CLASSNAME_H
#define _CLASSNAME_H

#include <iostream>
#include <iomanip>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <sstream>




using namespace std;


class AT_Cast{

	private:
		int ID;
		string name;

	public:

		AT_Cast(){

			ID = 0;
			name = "None";

		}
		AT_Cast(int ID, string name){

			this -> ID = ID;
			this -> name = name;

		}

		void setID(int ID){
			this -> ID = ID;
		}
		void setName(int name){
			this -> ID = ID;
		}

		int getID(){
			return ID;
		}
		string getName(){
			return name;
		}
	
		bool operator < (const AT_Cast& member){

			return ID < member.ID;

		}
		friend ostream &operator << (ostream &strm, AT_Cast &member){

			strm << "Cast ID Number: " << member.getID();
			strm << "\tName: " << member.getName() << endl;
			return strm;

		}


		

};


#endif