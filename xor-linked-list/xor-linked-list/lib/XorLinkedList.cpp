#include <stdexcept>
#include <string>
#include <iostream>

#include "XORLinkedList.h"

XORLinkedList::XORLinkedList() {
	this->__first = nullptr;
	this->__last = nullptr;
}

XORLinkedList::~XORLinkedList() {
	XORLinkedNode* current_node = this->__first;
	XORLinkedNode* prev_node = nullptr;
	XORLinkedNode* tmp_node = current_node;

	while (current_node != nullptr)
	{
		// Advance to the next node
		tmp_node = current_node;
		current_node = current_node->get_next_or_prev(prev_node);
		prev_node = tmp_node;

		delete prev_node;
	}
}

void XORLinkedList::add(int value) {
	XORLinkedNode* node_ptr = new XORLinkedNode(value, this->__last, nullptr);
	
	// If this is the first node
	if (this->__first == nullptr) {
		this->__first = node_ptr;
		this->__last = node_ptr;
		return;
	}

	// Set the `both` of the last node to the address of the new node XOR the address of the one before it.
	XORLinkedNode* prev_of_last = this->__last->get_next_or_prev(nullptr);
	this->__last->set_both(prev_of_last, node_ptr);
	this->__last = node_ptr;
}

int XORLinkedList::get(unsigned int index) {
	XORLinkedNode* current_node = this->__first;
	XORLinkedNode* prev_node = nullptr;
	XORLinkedNode* tmp_node = current_node;

	for (size_t i = 0; i < index; i++)
	{
		// Advance to the next node
		tmp_node = current_node;
		current_node = current_node->get_next_or_prev(prev_node);

		// Null means the list is over
		if (current_node == nullptr) {
			throw std::out_of_range("Attempted access to index " + std::to_string(index) + " in a list of length " + std::to_string(i + 1));
		}

		prev_node = tmp_node;
	}

	return current_node->get_value();
}