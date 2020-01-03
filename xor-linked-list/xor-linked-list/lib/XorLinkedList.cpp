#include <stdexcept>
#include <string>
#include <iostream>

#include "XORLinkedList.h"
#include "Utils.h"

XORLinkedList::XORLinkedList() {
	this->__first = nullptr;
	this->__last = nullptr;
}

XORLinkedList::~XORLinkedList() {
	XORLinkedNode* current_node = this->__first;
	XORLinkedNode* prev_node = nullptr;

	while (current_node != nullptr)
	{
		advance_node_ptrs(current_node, prev_node);

		// Delete the node before prev.
		// Deleting prev itself results in undefined behavior because 
		// its value is used in the next iteration.
		delete prev_node->get_next_or_prev(current_node);
	}

	// Delete the last remaining node in the list because
	// the loop stops before it can delete it.
	delete this->__last;
}


// Copy
XORLinkedList::XORLinkedList(const XORLinkedList& other) {
	this->__first = other.__first;
	this->__last = other.__last;

	XORLinkedNode* current_node = other.__first;
	XORLinkedNode* prev_node = nullptr;

	while (current_node != nullptr)
	{
		this->add(current_node->get_value());
		advance_node_ptrs(current_node, prev_node);
	}
}

XORLinkedList& XORLinkedList::operator=(const XORLinkedList& other) {
	XORLinkedNode* this_current_node = this->__first;
	XORLinkedNode* this_prev_node = nullptr;

	XORLinkedNode* other_current_node = other.__first;
	XORLinkedNode* other_prev_node = nullptr;
	
	while (this_current_node != nullptr && other_current_node != nullptr)
	{
		this_current_node->set_value(other_current_node->get_value());

		advance_node_ptrs(this_current_node, this_prev_node);
		advance_node_ptrs(other_current_node, other_prev_node);
	}

	// If there are more nodes in this linked list delete them
	while (this_current_node != nullptr)
	{
		advance_node_ptrs(this_current_node, this_prev_node);
		delete this_prev_node;
	}

	// Else, If there are more nodes in the other linked list, add them to this list
	while (other_current_node != nullptr)
	{
		this->add(other_current_node->get_value());
		advance_node_ptrs(other_current_node, other_prev_node);
	}

	return *this;
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
		advance_node_ptrs(current_node, prev_node);
		
		// Null means the list is over
		if (current_node == nullptr) {
			throw std::out_of_range("Attempted access to index " + std::to_string(index) + " in a list of length " + std::to_string(i + 1));
		}
	}

	return current_node->get_value();
}