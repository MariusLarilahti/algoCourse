#include <iostream>
#include "heap.h"
#include <chrono>
#include <random>


int main() {
	Heap h;
	//h.insert(17);
	//h.insert(11);
	//h.insert(6);
	//h.insert(14);
	//h.insert(22);
	//h.insert(8);
	//h.insert(1);
	//h.insert(16);
	//h.insert(10);
	//h.insert(19);
	//h.insert(12);
	//h.insert(3);
	//h.insert(5);
	//h.insert(15);
	//h.insert(13);


	//h.print();
	//h.delMin();
	//h.print();

	int sizes[] = { 100000, 1000000, 10000000 };

	for (int elements : sizes) {

		//fill arrays with random numbers
		std::mt19937 seed(67);
		std::uniform_int_distribution<int> dist(1, 1000);

		std::vector<int> data(elements);
		for (int i = 0; i < elements; ++i)
		{
			data[i] = dist(seed);
		}

		for (int i = 0; i < elements; ++i)
		{
			h.insert(data[i]);
		}


		auto sortStart = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < elements; ++i) {
			h.delMin();
		}

		auto sortStop = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> duration = sortStop - sortStart;
		std::cout << "sort took: " << duration.count() / 1000 << " seconds\n" << std::endl;
	}
	return EXIT_SUCCESS;
}
