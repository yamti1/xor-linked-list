#pragma once
#include <memory>
#include "XORLinkedListHandle.h"

class XORLinkedList
{
private:
	std::unique_ptr<XORLinkedListHandle> __list_handle;

public:
	XORLinkedList();
	int get(unsigned int index);
};

