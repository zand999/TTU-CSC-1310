

#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
#include <string>
using namespace std;

class LinkedList
{
	private:
		
		struct ListNode{

			string value; 
			struct ListNode *next = NULL;  
			
		}; 

		ListNode *head;		
		ListNode *tail;		

	public:
		
		LinkedList(){ 

			head = NULL; 
			tail = NULL;

		}
		~LinkedList(){

			ListNode *tempNode;
			ListNode *current = head;

			while(current != NULL){

				tempNode = current -> next;

				delete current;

				current = tempNode;



			}

		}
		void append(string value){

			ListNode *temp = new ListNode();
			temp -> value = value;
			if (!head ) {
				head = temp;
				tail = temp;
			}else{
				
				tail->next = temp;
				
				tail = temp;
			}


		}

		void displayList() const
		{
			ListNode *nodePtr; 

			if(head != NULL)
			{
				
				nodePtr = head;
				
				while (nodePtr)
				{
					
					cout << nodePtr->value << endl;
					nodePtr = nodePtr->next;
				}
			}
			else
				cout << "\nThere are no nodes in the list.\n\n";
		}


};
#endif