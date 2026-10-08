#pragma once
#include "node.h"

template<typename T> class Stack
{
public:

	Stack() { pTop = nullptr; }
	bool IsEmpty() { return pTop == nullptr; }

	void Push(T data) {
		Node<T>* pNew = new Node<T>(data); //create new node
		pNew->pNext = pTop; //point new to old top
		pTop = pNew; //set new as the new top
	}

	T Pop() {
		if (IsEmpty()) { return static_cast<T>(-1); }

		Node<T>* pDelete = pTop;
		T data = pDelete->data;
		pTop = pDelete->pNext;
		delete pDelete;

		return data;
	}

	T Top()
	{
		if (IsEmpty()) { return static_cast<T>(-1); } //generally try to make sure you dont call on empty stacks
		return pTop->data;
	}

private:
	Node<T>* pTop;
};

