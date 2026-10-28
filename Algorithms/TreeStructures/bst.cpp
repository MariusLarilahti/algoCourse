#include "bst.h"
#include <iostream>

//Smaller values are inserted on the left and equal & greater values on the right
void BST::Insert(int key)
{
	//create new node
	BSTNode* pNewNode = new BSTNode(key);

	if (IsEmpty()) {
		//set the new node with key value as the root node
		pRoot = pNewNode;
		return;
	}
	else {
		//tree is not empty:
		BSTNode* pCurrent = pRoot;
		BSTNode* pCandidate = pRoot;
		while (pCandidate != nullptr)
		{
			pCurrent = pCandidate;

			if (pNewNode->key < pCurrent->key) {
				pCandidate = pCurrent->pLeft;
			}
				
			else {
				pCandidate = pCurrent->pRight;
			}
		}
		//Check which direction we need to put the new node in
		if (pNewNode->key < pCurrent->key) {
			pCurrent->pLeft = pNewNode;
		}
		else {
			pCurrent->pRight = pNewNode;
		}
	}
}

bool BST::Delete(int key)
{
	if (!Find(key))
	{
		return false;
	}
	else
	pRoot = DeleteX(pRoot, key);
	return true;

}

BSTNode* BST::DeleteX(BSTNode* root, int key) 
{
	if (!root) return root; //if root not found

	if (key < root->key)  //key is less than root value -> key must be on the left side of root
	{ 
		root->pLeft = DeleteX(root->pLeft, key); 
		return root;
	}
	
	else if (key > root->key)  //key is greater than root value -> key must be on the right side of root
	{ 
		root->pRight = DeleteX(root->pRight, key); 
		return root;
	}

	if (!root->pLeft) return root->pRight; //no child on left
	if (!root->pRight) return root->pLeft; //no child on right

	BSTNode* node = root->pRight;
	while (node->pLeft) node->pLeft;
	node->pLeft = root->pLeft;
	root = root->pRight;

	return root;
}


void BST::Print() 
{
	PrintTree("", pRoot, false);
}

void BST::PrintTree(const std::string& prefix, const BSTNode* node, bool isLeft)
{
	if (node != nullptr)
	{
		std::cout << prefix;

		std::cout << (isLeft ? "|---" : "`-");

		// print the value of the node
		std::cout << node->key << std::endl;

		// enter the next tree level - left and right branch
		PrintTree(prefix + (isLeft ? "|   " : "    "), node->pLeft, true);
		PrintTree(prefix + (isLeft ? "|   " : "    "), node->pRight, false);
	}
}



bool BST::Find(int key) 
{
	return RecFind(pRoot, key);
}

bool BST::RecFind(BSTNode* pNode, int key) 
{
	if (pNode == nullptr || pNode->key == key)
		return pNode;

	else if (key < pNode->key) { return RecFind(pNode->pLeft, key); }

	else { return RecFind(pNode->pRight, key); }
}



int BST::CountNodes()
{
	return RecCountNodes(pRoot);
}
int BST::RecCountNodes(BSTNode* pNode)
{
	if (pNode == nullptr) return 0;

	return RecCountNodes(pNode->pLeft) + RecCountNodes(pNode->pRight) + 1;
}


int BST::CountLeaves()
{
	return RecCountLeaves(pRoot);
}
int BST::RecCountLeaves(BSTNode* pNode)
{
	if (pNode == nullptr) return 0;

	//return 1 when no more branches are available
	if (pNode->pLeft == nullptr && pNode->pRight == nullptr) return 1; 

	return RecCountLeaves(pNode->pLeft) + RecCountLeaves(pNode->pRight);
}




