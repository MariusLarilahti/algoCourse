#pragma once
#include <vector>
#define MAX_SIZE 255

class Heap
{
public:
	//make big to handle big tests
	Heap(int capacity = 10000000)
	{
		heapArray.resize(capacity + 1);
		heapArray[0] = 0; // length is stored at index 0
	}

	void insert(int key);
	void heapify(int i);
	void delMin();
	void print();
	int length() { return heapArray[0]; } //return the current length (stored at index 0)

private:
	std::vector<int> heapArray;
};