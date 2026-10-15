#pragma once
#include "bstnode.h"

class BST
{
public:
	//constructor that just sets root-node's pointer to null
	BST() {
		pRoot = nullptr;
	}

	bool IsEmpty() { return pRoot = nullptr; } //return true when pRoot is null

	void Insert(int key);

private:

	//pointer to the root of the BST
	BSTNode* pRoot;


};

