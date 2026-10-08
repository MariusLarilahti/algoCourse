#include <iostream>
#include <cstdio>
#include "Stack.h"


using namespace std;

int main(int argc, char** argv) {

	//check amount of params
	if (argc < 2) {
		cout << "Not enough arguments! You called: " << argv[0] << endl;
		return EXIT_FAILURE;
	}
	else {
		cout << "OK, You called: " << argv[0] << " " << argv[1] << endl;
		FILE* fp = NULL;
		errno_t error = fopen_s(&fp, argv[1], "r");
		if (fp == NULL){
			cout << "ERROR Opening file: " << argv[1] << endl;
			return EXIT_FAILURE;
		}
		//Read file one char at a time
		while (char c = fgetc(fp) != EOF) {
			cout << c;
		}
		cout << endl;

		fclose(fp);
		return EXIT_SUCCESS;
	}

	//Stack<int> s;

	//for (int i = 0; i < 10; i++)
	//{
	//	s.Push(i);
	//	cout << s.Top() << endl;
	//}
	//cout << "-x-x-x-" << endl;
	//for (int i = 0; i < 10; i++)
	//{
	//	int value = s.Pop();
	//	cout << value << endl;
	//}



	return EXIT_SUCCESS;
}