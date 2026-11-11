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

void Heap::heapify(int i)
{
	while (true)
	{
		int smallest = i; // Initialize smallest as root
		int l = 2 * i; // left = 2*k + 1
		int r = 2 * i + 1; // right = 2*k + 2

		// If left child is smaller than root
		if (l <= length() && heapArray[l] < heapArray[smallest])
			smallest = l;

		// If right child is smaller than smallest so far
		if (r <= length() && heapArray[r] < heapArray[smallest])
			smallest = r;

		// If smallest is not root
		if (smallest != i) {
			std::swap(heapArray[i], heapArray[smallest]);
			i = smallest;
		}
		else
		{
			break;
		}
	}
}


void Heap::delMin()
{
	if (length() < 1)
	{
		return;
	}
	else
	{
		int lastElement = heapArray[length()];
		heapArray[1] = lastElement;
		heapArray[0]--;

		heapify(1);
	}
}

void Heap::print()
{
	for (int i = 1; i <= length(); i++)
	{
		std::cout << heapArray[i] << ", ";
	}
	std::cout << std::endl;
}
