#pragma once

#include "XORLinkedNode.h"

class XORLinkedList
{
private:
	XORLinkedNode* __first;
	XORLinkedNode* __last;

public:
	XORLinkedList();

	void add(int value);
	int get(unsigned int index);
};

