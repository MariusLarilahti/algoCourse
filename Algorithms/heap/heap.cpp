#include <iostream>
#include "heap.h"

void Heap::insert(int key)
{
	//if going over the maximum heapsize:
	//TODO


	//if heap is empty
	if (length() < 1) 
	{
		heapArray[1] = key;
		heapArray[0]++; //increment length of the heap
		return;
	}
	//heap isn't empty
	else 
	{
		//insert key into first available slot
		int index = length() + 1;
		heapArray[index] = key;

		//increment length of the heap
		heapArray[0]++;

		//while heaporder not guaranteed AND we are not at at root (index 1) yet:
		//	- track the newly inserted element
		//	- swap places with parent
		int parentIndex = index / 2;
		while (heapArray[parentIndex] > heapArray[index] && index > 1)
		{
			//Swap indeces
			int tmp = heapArray[parentIndex];
			heapArray[parentIndex] = heapArray[index];
			heapArray[index] = tmp;

			//Update indices
			index = parentIndex;
			parentIndex = index / 2;
		}
	}

}

int Heap::delMin()
{
	return 0;
}

void Heap::print()
{
	for (int i = 1; i <= length(); i++)
	{
		std::cout << heapArray[i] << ", ";
	}
	std::cout << std::endl;
}
