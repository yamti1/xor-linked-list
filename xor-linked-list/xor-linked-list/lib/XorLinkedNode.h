#pragma once
#include <cstdint>

class XORLinkedNode
{
private:
	std::intptr_t __both;
	int __value;

public:
	// TODO: Change it to prev and then next.
	XORLinkedNode(int value, XORLinkedNode* next, XORLinkedNode* prev);

	XORLinkedNode* get_next_or_prev(XORLinkedNode* other);
	void set_both(XORLinkedNode* prev, XORLinkedNode* next);
};

