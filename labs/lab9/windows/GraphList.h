

#ifndef GRAPHLIST_H
#define GRAPHLIST_H
#include <string>
#include <iostream>

using namespace std;


class GraphList{
	private:

		struct ListNode{

			int value; 
			struct ListNode *next = NULL;  
			
		}; 

		ListNode **headArray;
		int numVertices;
		int numEdges;

	public:
		
		GraphList(int size){

			headArray = new ListNode*[size];
			numVertices = size;
			for(int i = 0; i < size; i++){
				ListNode* temp = new ListNode;
    
				temp -> value = i;
				headArray[i] = temp;
			}
		}


		~GraphList(){

			ListNode *nextNode;
			ListNode *currNode;
			
			for(int i=0; i<numVertices; i++){
				
				currNode = headArray[i];
				while(currNode != NULL){
					nextNode = currNode -> next;
					delete currNode;
					currNode = nextNode;

				}
				
			}
			delete[] headArray;

		}

		void addEdge(int location, int data){

			

			ListNode *currPtr = headArray[location];

			while(currPtr -> next != NULL){
				currPtr = currPtr -> next;
			}
			currPtr -> next = new ListNode;
			currPtr = currPtr -> next;
			currPtr -> value = data;

			

		}

		void printGraph(){
			cout << "\nAdjancency List. . .\n";
			
			ListNode *nodePtr;
			

			
			for(int i=0; i<numVertices; i++){
				
				nodePtr = headArray[i];
				while(nodePtr -> next != NULL){
					cout << nodePtr -> value << "--->";
					nodePtr = nodePtr -> next;

				}
				cout << nodePtr -> value << "--->";
				cout << "NULL\n";
				
			}
			
			

		}
};

#endif