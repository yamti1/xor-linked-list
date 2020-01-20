#include <stdexcept>
#include <string>
#include <iostream>
#include <memory>

#include "XORLinkedList.h"
#include "XORLinkedNode.h"
#include "Utils.h"


XORLinkedList::XORLinkedList() :
	__list_handle(std::make_unique<XORLinkedListHandle>()) 
{}

int XORLinkedList::get(unsigned int index) {
	XORLinkedNode* current_node = this->__list_handle.get()->get_first();
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

void XORLinkedList::add(int value) {
	return this->__list_handle.get()->add(value);
}