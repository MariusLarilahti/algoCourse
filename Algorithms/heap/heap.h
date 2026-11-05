#pragma once
#define MAX_SIZE 255

class Heap
{
public:
	Heap() { heapArray[0] = 0; } //initialize the current length to 0 (length is always stored at index 0)

	void insert(int key);
	int delMin();
	void print();
	int length() { return heapArray[0]; } //return the current length (stored at index 0)

private:
	int heapArray[MAX_SIZE + 1];


};