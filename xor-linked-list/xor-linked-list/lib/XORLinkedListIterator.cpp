#include "XORLinkedListIterator.h"
#include "Utils.h"

XORLinkedListIterator::XORLinkedListIterator(XORLinkedNode* const first)
	: __iterator(first) 
{}

XORLinkedListIterator::__Iterator XORLinkedListIterator::begin()
{
	return this->__iterator;
}

XORLinkedListIterator::__Iterator XORLinkedListIterator::end()
{
	return __Iterator(nullptr);
}

XORLinkedListIterator::__Iterator::__Iterator(XORLinkedNode* const first) : 
	__current_node(first), 
	__prev_node(nullptr)
{}

void XORLinkedListIterator::__Iterator::operator++()
{
	advance_node_ptrs(this->__current_node, this->__prev_node);
}

int XORLinkedListIterator::__Iterator::operator*()
{
	return this->__current_node->get_value();
}

bool XORLinkedListIterator::__Iterator::operator==(const __Iterator& other)
{
	// This causes the iteration to stop because `other` is the `end` iterator which has __current_node of null.
	return this->__current_node == other.__current_node;
}

bool XORLinkedListIterator::__Iterator::operator!=(const __Iterator& other)
{
	return !(*this == other);
}
