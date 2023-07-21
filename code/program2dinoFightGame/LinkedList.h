

#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
#include <string>
using namespace std;

template<typename vartype>
class LinkedList{

	private:
		
		struct ListNode{

			vartype value; 
			ListNode *next;  
			
		}; 

		ListNode *head;		
		ListNode *tail;	
		int numNodes;	

	public:
		
		//default constructor
		LinkedList(){ 

			head = NULL; 
			tail = NULL;
			numNodes = 0;
			
		}
		//deconstructor to dealocate memory
		~LinkedList(){

			ListNode *tempNode;
			ListNode *current = head;

			while(current != NULL){

				tempNode = current -> next;

				delete current;

				current = tempNode;



			}

		}

		//return length of linked list
		int getLength(){
			return numNodes;
		}

		//return the data of data of a node in the list
		vartype getNodeValue(int index){

			ListNode* node = head;
			for(int i = 0; i < index; i++) {
				node = node->next;
			}
			return node -> value;

		}

		//add a node at the end of the linked list
		void appendNode(vartype value){

			ListNode *temp = new ListNode;
			temp -> value = value;
			if (!head ) {
				head = temp;
				tail = temp;
			}else{
				
				tail->next = temp;
				
				tail = temp;
			}
			numNodes++;

			
		}

		//insert a node in the list at the selected index
		void insertNode(vartype value, int index){
			ListNode* node = head;
			for(int i = 0; i < index - 1; i++) {
				node = node->next;
			}
			ListNode* temp = new ListNode;
			temp->value = value;
			temp->next = node->next;
			node->next = temp;
			numNodes++;
		}

		//print out the contents of the linked list
		void displayList() const{
			ListNode *nodePtr; 

			if(head != NULL){
				
				nodePtr = head;
				
				while (nodePtr){
					
					cout << nodePtr->value << endl;
					nodePtr = nodePtr->next;
				}
			}
			else{
				cout << "\nThere are no nodes in the list.\n\n";
			}

			
		}


		

		

		void deleteNode(int index){
			ListNode* node = head;
			for(int i = 0; i < index - 1; i++) {
				node = node->next;
			}
			ListNode* nextNode = node->next->next;
			delete node->next;
			node->next = nextNode;
			numNodes--;
		}

		
};
#endif