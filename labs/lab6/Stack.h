

#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;


template <typename vartype>
class Stack{

   private:
     
      //create linked list 
      struct StackNode{
         vartype value; 
         StackNode *previous; 
      };
      
      //pointer to top of the stack
      StackNode *top; 

   public:
     
     //default constructor
      Stack(){
         top = NULL; 
      }
   
      //deconstuctor
      ~Stack(){
         StackNode *nodePtr, *nextNode;

         nodePtr = top;

         while (nodePtr != NULL){
            nextNode = nodePtr->next;
            delete nodePtr;
            nodePtr = nextNode;
         }
      }
   
      //add node to top of the stack
      void push(vartype item){
         StackNode *newNode = new StackNode;

         newNode->value = item;

         if (isEmpty()){

            top = newNode;
            newNode->previous = NULL;

         }else{

            newNode->previous = top;
            top = newNode;

         }
      }
      //get node from the top of the stack
      void pop(vartype &item){
         StackNode *temp = NULL;

         
         if (isEmpty()){
            cout << "The stack is empty.\n";
         }else{
            item = top->value;
            temp = top->previous;
            delete top;
            top = temp;
         }
      }

      //check if the stack is empty
      bool isEmpty(){
         bool status;

         if (!top){
            status = true;
         }else{
            status = false;
         }

         return status;
      }
};

#endif