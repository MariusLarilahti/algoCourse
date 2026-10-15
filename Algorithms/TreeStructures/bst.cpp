#include "bst.h"

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
