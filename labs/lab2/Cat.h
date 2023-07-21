// Specification file for the ContactInfo class.


#include <cstring>	// Needed for strlen and strcpy
#include <iostream>
using namespace std;

class Cat{

	private:
		string name,breed,color;
		int age;
		

	public:

		Cat(string name, string breed, string color, int age){
			this -> name = name;
			this -> breed = breed;
			this -> color = color;
			this -> age = age;
		}
	friend ostream & operator << (ostream& os, const Cat& c)
		{
			os << c.name <<  ", " << c.breed <<  ", " << c.color <<  ", " << c.age << "\n";
			return os;
		}

};

