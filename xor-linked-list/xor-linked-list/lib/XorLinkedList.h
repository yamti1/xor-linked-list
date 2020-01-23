#pragma once
#include "XORLinkedListHandle.h"

class XORLinkedList
{
private:
	XORLinkedListHandle __list_handle;
	int __length;

public:
	XORLinkedList();

	int get_length();

	int get(unsigned int index);
	int get_reverse(unsigned int index);
	void add(int value);

	int operator[](int index);
};

