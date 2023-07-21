


#include <iostream>

using namespace std;


class Wizard {
	public:
		Wizard(string name, int age, double height) {
			this->name = name;
			this->age = age;
			this->height = height;
		}
		
		friend ostream& operator << (ostream& o, Wizard& s) {
			o << s.name << ", " << s.age << ", " << s.height << "\n";
			return o;
		}
		
	private:
		string name;
		int age;
		double height;
};