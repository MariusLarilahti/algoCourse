#include "LinkedList.h"
#include <iostream>

using namespace std;

int main() {
	LinkedList ll;	

	cout << "IsEmpty(): " << ll.IsEmpty() << endl;
	for (int i = 1; i < 100; i++) {
		ll.Insert(i);
	}

	for (int i = 100; i >=1; i--) {
		ll.Delete(i);
	}
	cout << "IsEmpty(): " << ll.IsEmpty() << endl;
	//ll.InsertEnd(420);

	ll.Print();

	//if (ll.Delete(-1)) {
	//	cout << "Deleted" << endl;
	//}
	//else cout << "NOT Deleted" << endl;


	/*if (ll.Find(10)) {
		cout << "FOUND" << endl;
	}
	else cout << "NOT FOUND" << endl;*/

	return EXIT_SUCCESS;
}