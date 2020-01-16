#include <stdexcept>
#include <string>
#include <iostream>

#include "XORLinkedList.h"
#include "Utils.h"


// Delete all nodes from `current_node` to the end of the list.
// current_node: The first node to be deleted. May be null.
// prev_node: The node before current_node. May be null.
void XORLinkedList::_delete_nodes_from(XORLinkedNode* current_node, XORLinkedNode* prev_node)
{
	if (current_node == nullptr) return;

	// Move to the next node so that the node before `prev_node` won't be deleted.
	advance_node_ptrs(current_node, prev_node);

	while (current_node != nullptr)
	{
 		advance_node_ptrs(current_node, prev_node);

		// Delete the node before prev.
		// Deleting prev itself results in undefined behavior because 
		// its value is used in the next iteration.
		delete prev_node->get_next_or_prev(current_node);
	}

	// Delete the last remaining node because
	// the loop stops before it can delete it.
	delete prev_node;
}


XORLinkedList::XORLinkedList() {
	this->__first = nullptr;
	this->__last = nullptr;
}

XORLinkedList::~XORLinkedList() {
	_delete_nodes_from(this->__first, nullptr);
}


// Copy Constructor
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

// Swaps this with another XORLinkedList
void XORLinkedList::__swap(XORLinkedList& other) {
	XORLinkedNode* tmp = this->__first;
	this->__first = other.__first;
	other.__first = tmp;

	tmp = this->__last;
	this->__last = other.__last;
	other.__last = tmp;
}

// Copy Assignement
XORLinkedList& XORLinkedList::operator=(XORLinkedList tmp) {
	// Implements the Copy-and-Swap Idiom:
	// The assigned object `tmp` is copied when it is passed as an argument to this method.
	// Then it is swapped with `this`,
	// And then, when the method returns, `tmp` is deleted.
	this->__swap(tmp);
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