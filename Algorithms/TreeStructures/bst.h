#pragma once
#include "bstnode.h"
#include <string>

class BST
{
public:
	//constructor that just sets root-node's pointer to null
	BST() {
		pRoot = nullptr;
	}

	bool IsEmpty() { return pRoot == nullptr; } //return true when pRoot is null

	void Insert(int key);
	void Print();

	bool Find(int key);
	bool Delete(int key);

	int CountNodes();
	int CountLeaves();


private:

	//pointer to the root of the BST
	BSTNode* pRoot;

	bool RecFind(BSTNode* pNode, int key);
	int RecCountNodes(BSTNode* pNode);
	int RecCountLeaves(BSTNode* pNode);
	void PrintTree(const std::string& prefix, const BSTNode* node, bool isLeft);

	BSTNode* DeleteX(BSTNode* pNode, int key);
};

