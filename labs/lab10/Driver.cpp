
#include "ArrayMaxHeap.h"
#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

void display(string& anItem){
   cout << "Displaying item - " << anItem << endl;
}

int main(){
   ArrayMaxHeap *Students = new ArrayMaxHeap(50); 
   
   Students -> insert(Student(2.6,"Cosette Mealbone","HPC"));
   Students -> insert(Student(4.0,"April Crockett","HPC"));
   Students -> insert(Student(3.8,"Beatrix Longbottom","CYBERSECURITY"));
   Students -> insert(Student(3.9,"Blaire Strange","DATA SCIENCE"));
   Students -> insert(Student(2.9,"Cybil Lidscrew","CSSC"));
   Students -> insert(Student(1.4,"Coco Mobo","DATA SCIENCE"));
   Students -> insert(Student(3.2,"Alabama Joebob","CSSC"));
   Students -> insert(Student(3.6,"Diem Carpefat","HPC"));
   Students -> insert(Student(3.9,"Chichi Musicpaper","CSSC"));
   Students -> insert(Student(2.7,"Bentlee Caryellow","CYBERSECURITY"));
  
   while (!Students->isEmpty()){
      cout << "# of nodes: " << Students->getNumberOfNodes() << endl;
      cout << "Height: "     << Students->getHeight() << endl;
      cout << "max value: "  << Students->peek() << endl;
      Students->remove();
   }  

   

   return 0;
}  