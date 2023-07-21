

#ifndef List_H
#define List_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class LinkedList{
	private:
		// Declare a structure for the list
		struct ListNode {
			string value; 
			struct ListNode *next;  	// To point to the next node
			/*
				because this structure contains a pointer to an object
				of the same type as that being declared, it is 
				called a self-referential data structure
			*/
		}; 
		ListNode *head;		//List head pointer
		ListNode *tail;		//List tail pointer

	public:
		// Constructor
		LinkedList() { 
			tail = NULL;
			head = NULL;
		}

		// Destructor (deallocates all nodes)
		~LinkedList() {
			ListNode* node = head, *lastNode;
			while(node->next != NULL) {
				lastNode = node;
				node = node->next;
				delete lastNode;

			}
		}

		// Linked list operations
		void appendNode(string value){
			ListNode* temp = new ListNode;
			temp -> value = value;
			if(tail !=  NULL) tail -> next = temp;
			tail = temp;
			if(head == NULL) head = temp;

		}

		void insertNode(string value, int index){
			ListNode* node = head;
			for(int i = 0; i < index - 1; i++) {
				node = node->next;
			}
			ListNode* temp = new ListNode;
			temp->value = value;
			temp->next = node->next;
			node->next = temp;
		}

		void deleteNode(int index){
			ListNode* node = head;
			for(int i = 0; i < index - 1; i++) {
				node = node->next;
			}
			ListNode* nextNode = node->next->next;
			delete node->next;
			node->next = nextNode;
		}

		void displayList() {
			ListNode* node = head;
			while(node != NULL) {
				std::cout << node->value << "\n";

				node = node->next;
			}
		}
};

#endif