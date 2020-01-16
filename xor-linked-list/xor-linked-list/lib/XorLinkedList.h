#pragma once

#include "XORLinkedNode.h"

class XORLinkedList
{
private:
	XORLinkedNode* __first;
	XORLinkedNode* __last;
	void __swap(XORLinkedList& other);

protected:
	void _delete_nodes_from(XORLinkedNode* current_node, XORLinkedNode* prev_node);

public:
	XORLinkedList();
	~XORLinkedList();

	// Copy
	XORLinkedList(const XORLinkedList& other);
	XORLinkedList& operator=(XORLinkedList tmp);

	// TODO: Move

	void add(int value);
	int get(unsigned int index);
};

