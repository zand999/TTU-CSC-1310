

#ifndef HASHENTRY_H
#define HASHENTRY_H
#include <string>
#include <iostream>
//#include "HashTable.h"
#include "Classname.h"


using namespace std;

template<typename vartype>
class HashEntry{
	private:
		int key;
		vartype value;
		HashEntry* next;
		
	public:
		HashEntry(int k, vartype v){
			this->key = k;
			this->value = v;
			this->next = NULL;
		}
		HashEntry(){}

		int getKey(){
			return key;
		}

		vartype getValue(){
			return value;
		}

		HashEntry* getNext(){
			return next;
		}

		void setNext(HashEntry *next){
			this->next = next;
		}

		void setValue(vartype v){
			value = v;
		}
};

#endif