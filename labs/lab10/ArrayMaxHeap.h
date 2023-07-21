
#ifndef _ARRAY_MAX_HEAP
#define _ARRAY_MAX_HEAP
#include <cmath>
#include <iostream>
#include "Student.h"
using namespace std;



class ArrayMaxHeap{
	private:
						
		Student* items;      
		int heap_size;                    
		int capacity;                          

		void swap(Student *x, Student *y){
			Student temp = *x;
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
		
			return (left(nodeIndex) >= heap_size);
		}


		void heapRebuild(const int subTreeNodeIndex){
			if (!isLeaf(subTreeNodeIndex)){
				// Find larger child
				int leftChildIndex = left(subTreeNodeIndex);  
				int largerChildIndex = leftChildIndex;        
				int rightChildIndex = right(subTreeNodeIndex); 

				
				if (rightChildIndex < heap_size){
					
					if (items[rightChildIndex] > items[largerChildIndex]){
						largerChildIndex = rightChildIndex;	
					}
				}	
				if (items[subTreeNodeIndex] < items[largerChildIndex]){

					swap(&items[largerChildIndex], &items[subTreeNodeIndex]);

					heapRebuild(largerChildIndex);
				}  
			}  
		} 

		
		void heapCreate(){
		   for (int index = heap_size / 2; index >= 0; index--)
		   {
		      heapRebuild(index);  
		   } 
		}

	public:
		ArrayMaxHeap(int num){  
			heap_size = 0;
			capacity = num;
			items = new Student[capacity];
		}

		~ArrayMaxHeap(){  
		   delete [] items;
		} 

						
		bool isEmpty() const{ 

			if(heap_size == 0)
				return true;
			else
				return false;
		} 
		
		int getNumberOfNodes() const{ 
			return heap_size;
		}  
		
		int getHeight() const{ 

			return ceil(log2(heap_size + 1));

		} 

		Student peek() const{
		   return items[0];
		}

			
		void insert(Student newData){ 
			
			
			items[heap_size] = newData;
			heap_size++;

		
			int i = heap_size-1;
			while ((i != 0) && (items[parent(i)] < items[i])){
				swap(&items[i], &items[parent(i)]);
				i = parent(i);
			} 
		} 
						
		Student remove(){
			Student temp;
			if (!isEmpty()) 
			{
				temp = items[0];
				items[0] = items[heap_size - 1];		
				heap_size--;							
				heapRebuild(0);							
			}
			else
			{
				cout << "\nThe heap is empty so I can't remove any values.\n";
			}

			return temp;
		} 

}; 




#endif
