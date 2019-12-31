#pragma once

#include "XORLinkedNode.h"

class XORLinkedList
{
private:
	XORLinkedNode* __first;
	XORLinkedNode* __last;

public:
	XORLinkedList();
	~XORLinkedList();

	// Copy
	XORLinkedList(const XORLinkedList& other);
	XORLinkedList& operator=(const XORLinkedList& other);

	void add(int value);
	int get(unsigned int index);
};

