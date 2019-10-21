#pragma once
#include <cstdint>

class XorLinkedNode
{
private:
	std::intptr_t __both;
	int __value;

public:
	XorLinkedNode(int value, XorLinkedNode* next, XorLinkedNode* prev);

	XorLinkedNode* get_next_or_prev(XorLinkedNode* other);
	void set_both(XorLinkedNode* prev, XorLinkedNode* next);
};

