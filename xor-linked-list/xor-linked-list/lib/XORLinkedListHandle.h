#pragma once

#include <utility>

#include "XORLinkedNode.h"


template <class T>
void advance_node_ptrs(XORLinkedNode<T>*& current_node, XORLinkedNode<T>*& prev_node) {
	XORLinkedNode<T>* tmp_node = current_node;
	current_node = current_node->get_next_or_prev(prev_node);
	prev_node = tmp_node;
}


template <class T>
class XORLinkedListHandle {
private:
	XORLinkedNode<T>* __first;
	XORLinkedNode<T>* __last;
	void __swap(XORLinkedListHandle<T>& other) {
		std::swap(this->__first, other.__first);
		std::swap(this->__last, other.__last);
	}

public:
	XORLinkedListHandle() {
		this->__first = nullptr;
		this->__last = nullptr;
	}

	~XORLinkedListHandle() {
		XORLinkedNode<T>* current_node = this->__first;
		XORLinkedNode<T>* prev_node = nullptr;

		while (nullptr != current_node )
		{
			advance_node_ptrs<T>(current_node, prev_node);

			// Delete the node before prev.
			// Deleting prev itself results in undefined behavior because 
			// its value is used in the next iteration.
			delete prev_node->get_next_or_prev(current_node);
		}

		// Delete the last node because
		// the loop stops before it can delete it.
		delete this->__last;
	}

	// Copy
	XORLinkedListHandle(const XORLinkedListHandle<T>& other) {
		this->__first = nullptr;
		this->__last = nullptr;

		XORLinkedNode<T>* current_node = other.__first;
		XORLinkedNode<T>* prev_node = nullptr;

		while (nullptr != current_node)
		{
			this->add(current_node->get_value());
			advance_node_ptrs<T>(current_node, prev_node);
		}
	}

	XORLinkedListHandle<T>& operator=(XORLinkedListHandle<T> tmp) {
		// Implements the Copy-and-Swap Idiom:
		// The assigned object `tmp` is copied when it is passed as an argument to this method.
		// Then it is swapped with `this`,
		// And then, when the method returns, `tmp` is deleted.
		this->__swap(tmp);
		return *this;
	}

	// Move
	XORLinkedListHandle(XORLinkedListHandle<T>&& other) noexcept {
		this->__swap(other);
	}

	XORLinkedListHandle<T>& operator=(XORLinkedListHandle<T>&& other) noexcept {
		this->__swap(other);
		return *this;
	}
	
	XORLinkedNode<T>* get_first() { return this->__first; }
	XORLinkedNode<T>* get_last() { return this->__last; }

	void add(T value) {
		XORLinkedNode<T>* node_ptr = new XORLinkedNode<T>(value, this->__last, nullptr);

		// If this is the first node
		if (nullptr == this->__first) {
			this->__first = node_ptr;
			this->__last = node_ptr;
			return;
		}

		// Set the `both` of the last node to the address of the new node XOR the address of the one before it.
		XORLinkedNode<T>* prev_of_last = this->__last->get_next_or_prev(nullptr);
		this->__last->set_both(prev_of_last, node_ptr);
		this->__last = node_ptr;
	}
};
