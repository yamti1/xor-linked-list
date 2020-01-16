#pragma once

#include "XORLinkedNode.h"

class XORLinkedList
{
private:
	XORLinkedNode* __first;
	XORLinkedNode* __last;
	void __swap(XORLinkedList& other);

public:
	XORLinkedList();
	~XORLinkedList();

	// Copy
	XORLinkedList(const XORLinkedList& other);
	XORLinkedList& operator=(XORLinkedList tmp);

	// Move
	XORLinkedList(XORLinkedList&& other);

	void add(int value);
	int get(unsigned int index);
};

