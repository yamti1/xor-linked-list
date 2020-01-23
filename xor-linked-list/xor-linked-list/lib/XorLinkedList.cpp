#include <stdexcept>
#include <string>
#include <iostream>

#include "XORLinkedList.h"
#include "XORLinkedNode.h"
#include "Utils.h"


XORLinkedList::XORLinkedList() :
	__list_handle(XORLinkedListHandle()),
	__length()
{}

int XORLinkedList::get_length() {
	return this->__length;
}

// Get the value stored at index, starting from edge_node.
// index = 0 means the value at the edge node,
// index = 1 means the one value ofter that, etc.
int __get(XORLinkedNode* const edge_node, const unsigned int index) {
	if (nullptr == edge_node) {
		throw std::invalid_argument("Got nullptr as the edge node");
	}

	XORLinkedNode* current_node = edge_node;
	XORLinkedNode* prev_node = nullptr;
	XORLinkedNode* tmp_node = current_node;

	for (size_t i = 0; i < index; i++)
	{
		advance_node_ptrs(current_node, prev_node);

		// Null means the list is over
		if (current_node == nullptr) {
			throw std::out_of_range("Attempted access to index " + std::to_string(index) + " in a list of length " + std::to_string(i + 1));
		}
	}

	return current_node->get_value();
}

// Get the value stored at index.
// index = 0 means the first value.
int XORLinkedList::get(const unsigned int& index) {
	return __get(this->__list_handle.get_first(), index);
}

// Get the value stored at index, but reversed.
// index = 0 means the last value, 
// index = 1 means the value one before the last, etc.
int XORLinkedList::get_reverse(const unsigned int& index)
{
	return __get(this->__list_handle.get_last(), index);
}

void XORLinkedList::add(int value) {
	this->__list_handle.add(value);
	this->__length++;
}

// Get the value at the given index.
// May be given negative indexes for reverse indexing,
// where [-1] means the last value, [-2] means the value before that, etc.
int XORLinkedList::operator[](const int index)
{
	if (0 <= index) {
		return this->get(index);
	}

	try {
		// Negative indexes start at -1 but get_reverse indexes start at 0.
		unsigned int reverse_index = std::abs(index) - 1;
		return this->get_reverse(reverse_index);
	}
	catch (std::out_of_range) {
		// Change the error message to match the original index
		throw std::out_of_range("Attempted access to index " + std::to_string(index) + " in a list of length " + std::to_string(this->get_length()));
	}
}
