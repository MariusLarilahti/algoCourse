#include <iostream>
#include "heap.h"

int main() {
	Heap h;
	h.insert(17);
	h.insert(11);
	h.insert(6);
	h.insert(14);
	h.insert(22);
	h.insert(8);
	h.insert(1);
	h.insert(16);
	h.insert(10);
	h.insert(19);
	h.insert(12);
	h.insert(3);
	h.insert(5);
	h.insert(15);
	h.insert(13);


	h.print();
	for (int i = 0; i < 300; i++)
	{

	}

	return EXIT_SUCCESS;
}
