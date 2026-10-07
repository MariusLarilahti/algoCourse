// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"

using namespace std;



bool LinkedList::IsEmpty()
{
    return this->pHead == nullptr; // if pHead is empty, return true (1)
}

void LinkedList::Insert(int value)
{
    if (IsEmpty()) {

        Node* pNewNode = new Node(value); // create new node

        this->pHead = pNewNode; // update pHead to new node

    }
    else { // list not empty
        Node* pNewNode = new Node(value); // create new node

        pNewNode->pNext = pHead; //set new node's pNext to equal pHead

        pHead = pNewNode; // set pHead to point to equal pHead

    }
}

void LinkedList::InsertEnd(int value)
{
    if (IsEmpty()) {

        Node* pNewNode = new Node(value); // create new node

        this->pHead = pNewNode; // update pHead to new node

    }
    else { // list not empty
        Node* pNewNode = new Node(value); // create new node
        pNewNode->pNext = nullptr;        //set new node's pointer to nullptr as its the new end

        
        Node* pPrevious = this->pHead; // create temp p
        while (pPrevious->pNext != nullptr) { //find previous node
            pPrevious = pPrevious->pNext;
        }
        pPrevious->pNext = pNewNode; //set previously last node's pointer to this new node
    }
}

void LinkedList::Print()
{
    Node* pTemp = this->pHead; // create temp p, assing head p

    while (pTemp != nullptr) { // do until no more nodes left

        cout << pTemp->data << endl; // print node data

        pTemp = pTemp->pNext; // set p to next node
    }
}

bool LinkedList::Find(int value)
{
    Node* pTemp = this->pHead; // create temp p, assing head p

    while (pTemp != nullptr) { // do until list ends
        if (pTemp->data == value) //return if value is found
            return true;
        
        pTemp = pTemp->pNext; // set p to next node
        
    }

    return false;
}

bool LinkedList::Delete(int value)
{
    if (pHead == nullptr || value < 1) {
        cout << "Invalid value or empty list." << endl;
        return false;
    }
    //deleting head
    if (value == 1) {
        Node* pTemp = pHead;
        pHead = pHead->pNext;
        delete pTemp;
        return true;
    }

    //previous node
    Node* pPrev = pHead;
    for (int i = 1; i < value - 1 && pPrev != nullptr; i++) {
        pPrev = pPrev->pNext;
    }

    //is the node within limits
    if (pPrev == nullptr || pPrev->pNext == nullptr)
    {
        return false;
    }

    //link previous to the following, then delete the middle
    Node* pTemp = pPrev->pNext;
    pPrev->pNext = pTemp->pNext;
    delete pTemp;

    return true;
}