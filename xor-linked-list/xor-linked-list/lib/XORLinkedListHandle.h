#pragma once
#include "XORLinkedNode.h"

class XORLinkedListHandle {
private:
	XORLinkedNode* __first;
	XORLinkedNode* __last;
	void __swap(XORLinkedListHandle& other);

public:
	XORLinkedListHandle();
	~XORLinkedListHandle();

	// Copy
	XORLinkedListHandle(const XORLinkedListHandle& other);
	XORLinkedListHandle& operator=(XORLinkedListHandle tmp);

	// Move
	XORLinkedListHandle(XORLinkedListHandle&& other) noexcept;
	XORLinkedListHandle& operator=(XORLinkedListHandle&& other) noexcept;
	
	XORLinkedNode* get_first();
	XORLinkedNode* get_last();

	void add(int value);
};