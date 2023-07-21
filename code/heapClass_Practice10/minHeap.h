
#ifndef MIN_HEAP
#define MIN_HEAP
#include <cmath>
#include <iostream>
#include "string.h"
using namespace std;



class MinHeap{
	private:
						
		string* heap;      
		int sz;                    
		int capacity;                          

		void swap(string *x, string *y){
			string temp = *x;
			*x = *y;
			*y = temp;
		}			
		
		int parent(int i){ 		
		
			return (i-1)/2; 
		}
		int left(int i){		
		
			return (2*i + 1); 
		}
		int right(int i){ 			
		 
			return (2*i + 2); 
		}
		
		
		bool isLeaf(int nodeIndex){	
		
			return (left(nodeIndex) >= sz);
		}


		void heapRebuild(const int subTreeNodeIndex){
			if (!isLeaf(subTreeNodeIndex)){
				// Find larger child
				int leftChildIndex = left(subTreeNodeIndex);  
				int largerChildIndex = leftChildIndex;        
				int rightChildIndex = right(subTreeNodeIndex); 

				
				if (rightChildIndex > sz){
					
					if (heap[rightChildIndex].size() < heap[largerChildIndex].size()){
						largerChildIndex = rightChildIndex;	
					}
				}	
				if (heap[subTreeNodeIndex].size() > heap[largerChildIndex].size()){

					swap(&heap[largerChildIndex], &heap[subTreeNodeIndex]);

					heapRebuild(largerChildIndex);
				}  
			}  
		} 

		
		void heapCreate(){
		   for (int index = sz / 2; index >= 0; index--)
		   {
		      heapRebuild(index);  
		   } 
		}

		void resize(){
			string* newheap = new string[capacity * 2]; 
			for(int i = 0; i < sz; i++){
				newheap[i] = heap[i];
			}
			delete[] heap;
			heap = new string[capacity * 2];
			for(int i = 0; i < sz; i++){
				heap[i] = newheap[i];
			}
			capacity *= 2;
			delete[] newheap;

		}

	public:
		MinHeap(int num){  
			sz = 0;
			capacity = num;
			heap = new string[capacity];
		}

		~MinHeap(){  
		   delete [] heap;
		} 

						
		bool isEmpty() const{ 

			if(sz == 0)
				return true;
			else
				return false;
		} 
		
		int getNumberOfNodes() const{ 
			return sz;
		}  
		
		int getHeight() const{ 

			return ceil(log2(sz + 1));

		} 
		int getSize(){
			return sz;
		}

		string peek() const{
		   return heap[0];
		}

			
		void insert(string newData){ 
			
			if(sz + 1 == capacity){
				resize();
			}
			heap[sz] = newData;
			sz++;

		
			int i = sz-1;
			while ((i != 0) && (heap[parent(i)].size() > heap[i].size())){
				swap(&heap[i], &heap[parent(i)]);
				i = parent(i);
			} 
		} 
						
		string remove(){
			string temp;
			if (!isEmpty()) 
			{
				temp = heap[0];
				heap[0] = heap[sz - 1];		
				sz--;							
				heapRebuild(0);							
			}
			else
			{
				cout << "\nThe heap is empty so I can't remove any values.\n";
			}

			return temp;
		} 

		void clear(){

			delete[] heap;
			sz = 0;
		}

}; 




#endif
