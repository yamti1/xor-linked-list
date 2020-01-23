#pragma once
#include "XORLinkedListHandle.h"

class XORLinkedList
{
private:
	XORLinkedListHandle __list_handle;

public:
	XORLinkedList();

	int get(unsigned int index);
	void add(int value);
};

