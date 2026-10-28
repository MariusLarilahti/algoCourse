#include <iostream>
#include "bst.h"

int main() {



	BST bst;
	bst.Insert(5);
	bst.Insert(3);
	bst.Insert(8);
	bst.Insert(2);
	bst.Insert(4);
	bst.Insert(1);
	bst.Insert(7);
	bst.Insert(6);
	bst.Insert(9);
	bst.Insert(11);
	
	bst.Print();
	//bst.Delete(6);

	std::cout << "_________________________________________________" << std::endl;

	int x = 11;
	if (bst.Find(x)) {
		std::cout << "value: " << x << " WAS found in tree" << std::endl;
	}
	else
		std::cout << "value: " << x << " NOT found in tree" << std::endl;

	std::cout << "Leaves found in tree: " << bst.CountLeaves() << std::endl;;
	std::cout << "Nodes found in tree: " << bst.CountNodes() << std::endl;
	std::cout << "_________________________________________________" << std::endl;
	if (bst.Delete(7))
	{
		std::cout << "Deleted value successfully. Here's the new tree:" << std::endl;
		bst.Print();
	}
	else
		std::cout << "Value to be deleted was not found in the tree." << std::endl;
	std::cout << "_________________________________________________" << std::endl;
	
	
	return EXIT_SUCCESS;
}
