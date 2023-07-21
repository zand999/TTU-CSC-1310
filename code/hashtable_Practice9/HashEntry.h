

#ifndef HASHENTRY_H
#define HASHENTRY_H
#include <string>
#include <iostream>
using namespace std;

class HashEntry
{
	private:
		int key;
		string value;
		HashEntry* next;
		
	public:
		HashEntry(int k, string v)
		{
			this->key = k;
			this->value = v;
			this->next = NULL;
		}
		
		int getKey()
		{
			return key;
		}
		string getValue()
		{
			return value;
		}
		HashEntry* getNext()
		{
			return next;
		}
		void setNext(HashEntry *next)
		{
			this->next = next;
		}
		void setValue(string v)
		{
			value = v;
		}
};

#endif