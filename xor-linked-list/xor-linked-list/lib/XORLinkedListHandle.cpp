#include <utility>

#include "XORLinkedListHandle.h"
#include "Utils.h"


XORLinkedListHandle::XORLinkedListHandle() {
	this->__first = nullptr;
	this->__last = nullptr;
}

XORLinkedListHandle::~XORLinkedListHandle() {
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

	// Delete the last node because
	// the loop stops before it can delete it.
	delete this->__last;
}


// Copy Constructor
XORLinkedListHandle::XORLinkedListHandle(const XORLinkedListHandle& other) {
	this->__first = nullptr;
	this->__last = nullptr;

	XORLinkedNode* current_node = other.__first;
	XORLinkedNode* prev_node = nullptr;

	while (current_node != nullptr)
	{
		this->add(current_node->get_value());
		advance_node_ptrs(current_node, prev_node);
	}
}

// Swaps this with another XORLinkedListHandle
void XORLinkedListHandle::__swap(XORLinkedListHandle& other) {
	std::swap(this->__first, other.__first);
	std::swap(this->__last, other.__last);
}

// Copy Assignment
XORLinkedListHandle& XORLinkedListHandle::operator=(XORLinkedListHandle tmp) {
	// Implements the Copy-and-Swap Idiom:
	// The assigned object `tmp` is copied when it is passed as an argument to this method.
	// Then it is swapped with `this`,
	// And then, when the method returns, `tmp` is deleted.
	this->__swap(tmp);
	return *this;
}


// Move Contructor
XORLinkedListHandle::XORLinkedListHandle(XORLinkedListHandle&& other) noexcept {
	this->__swap(other);
}

// Move Assignment
XORLinkedListHandle& XORLinkedListHandle::operator=(XORLinkedListHandle&& other) noexcept {
	this->__swap(other);
	return *this;
}


void XORLinkedListHandle::add(int value) {
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


XORLinkedNode* XORLinkedListHandle::get_first() { return this->__first; }
XORLinkedNode* XORLinkedListHandle::get_last() { return this->__last; }