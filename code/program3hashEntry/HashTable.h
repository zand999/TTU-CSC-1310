
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <iomanip>
#include "HashEntry.h"
#include "Classname.h"
using namespace std;

template<typename vartype>
class HashTable{
	private:
		int tableSize;
		HashEntry<vartype> **hashArray;
	public:
		HashTable(int size){
			tableSize = size;
			hashArray = new HashEntry<vartype>*[tableSize];
			for(int i=0; i<tableSize; i++)
				hashArray[i] = NULL;
			
		}
		~HashTable(){
			for(int i=0; i<tableSize; i++){
				if(hashArray[i] != NULL){
					HashEntry<vartype> *prevEntry = NULL;
					HashEntry<vartype> *entry = hashArray[i];
					while(entry != NULL){
						prevEntry = entry;
						entry = entry->getNext();
						delete prevEntry;
					}
				}
			}
			delete [] hashArray;
			cout << "\nMemory released\n";
			
		}
		
		vartype getValue(int key){
			int bucketIndex = key % tableSize;
			if(hashArray[bucketIndex] == NULL){
				return NULL;
			}else{
				HashEntry<vartype> *entry = hashArray[bucketIndex];
				while(entry != NULL && entry->getKey() != key)
					entry = entry->getNext();
				if(entry == NULL)
					return NULL;
				else
					return entry->getValue();
			}

			return NULL;
		}
		
		void putValue(int key, vartype value){
			int bucketIndex = key % tableSize;
			cout << "BUCKET " << bucketIndex << endl;
			
			if(hashArray[bucketIndex] == NULL){
				hashArray[bucketIndex] = new HashEntry<vartype>(key, value);
			}else{
				HashEntry<vartype>* entry = hashArray[bucketIndex];
				while(entry->getNext() != NULL)
					entry = entry->getNext();
				if(entry->getKey() == key)
					entry->setValue(value);
				else
					entry->setNext(new HashEntry<vartype>(key, value));
			}
		}
		
		void removeValue(int key){


			HashEntry<vartype> *entry;
			HashEntry<vartype> *prevEntry;
			int bucketIndex = key% tableSize;
			if(hashArray[bucketIndex] != NULL){
				//traverse through list and find matched key
				prevEntry = NULL;
				entry = hashArray[bucketIndex];
				while(entry->getNext() != NULL & entry->getKey() != key){
					prevEntry = entry;
					entry = entry->getNext();
				}
				if(entry->getKey() == key){
					if(prevEntry == NULL){
						HashEntry<vartype> *nextEntry = entry->getNext();
						delete entry;
						hashArray[bucketIndex] = nextEntry; //re-link list 
					}else{
						HashEntry<vartype> *next = entry->getNext();
						delete entry;
						prevEntry->setNext(next);
					}
				}
			}		
		}
		
		void printHashTable(){
		
			cout << "----------\n";
			
			for(int i=0; i<tableSize; i++){
				if(hashArray[i] != NULL){
					HashEntry<vartype>* entry = hashArray[i];
					while(entry->getNext() != NULL){
						cout << "---->" << setw(4) << *(entry->getValue());
						entry = entry->getNext();
					}
					cout << "---->" << setw(4) << *(entry->getValue());
					cout << "\n";
				}
				else
					cout << setw(2) << "-->NULL\n";
			}
			cout << "----------\n\n";
			
		}
		
};


#endif