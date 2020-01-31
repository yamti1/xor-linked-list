#pragma once
#include "XORLinkedListHandle.h"
#include "XORLinkedListIterator.h"

class XORLinkedList
{
private:
	XORLinkedListHandle __list_handle;
	int __length;

public:
	XORLinkedList();

	int get_length();

	int get(const unsigned int& index);
	int get_reverse(const unsigned int& index);
	void add(int value);

	int operator[](int index);

	XORLinkedListIterator iter();
};

