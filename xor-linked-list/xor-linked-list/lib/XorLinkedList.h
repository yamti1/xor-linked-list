#pragma once
#include <stdexcept>
#include <string>

#include "XORLinkedListHandle.h"
#include "XORLinkedListIterator.h"

template <class T>
class XORLinkedList
{
private:
	XORLinkedListHandle<T> __list_handle;
	int __length;

	// Get the value stored at index, starting from edge_node.
	// index = 0 means the value at the edge node,
	// index = 1 means the one value ofter that, etc.
	T __get(XORLinkedNode<T>* const edge_node, const unsigned int index) {
		if (nullptr == edge_node) {
			throw std::invalid_argument("Got nullptr as the edge node");
		}

		XORLinkedNode<T>* current_node = edge_node;
		XORLinkedNode<T>* prev_node = nullptr;
		XORLinkedNode<T>* tmp_node = current_node;

		for (size_t i = 0; i < index; i++)
		{
			advance_node_ptrs<T>(current_node, prev_node);

			// Null means the list is over
			if (nullptr == current_node {
				throw std::out_of_range("Attempted access to index " + std::to_string(index) + " in a list of length " + std::to_string(i + 1));
			}
		}

		return current_node->get_value();
	}

public:
	XORLinkedList() :
		__list_handle(XORLinkedListHandle<T>()),
		__length()
	{}

	template <size_t N>
	XORLinkedList(const T (&arr)[N]) :
		__list_handle(XORLinkedListHandle<T>()),
		__length()
	{
		for (size_t i = 0; i < N; i++)
		{
			this->add(arr[i]);
		}
	}

	int get_length() {
		return this->__length;
	}

	// Get the value stored at index.
	// index = 0 means the first value.
	T get(const unsigned int& index) {
		return __get(this->__list_handle.get_first(), index);
	}

	// Get the value stored at index, but reversed.
	// index = 0 means the last value, 
	// index = 1 means the value one before the last, etc.
	T get_reverse(const unsigned int& index)
	{
		return __get(this->__list_handle.get_last(), index);
	}

	void add(T value) {
		this->__list_handle.add(value);
		this->__length++;
	}

	// Get the value at the given index.
	// May be given negative indexes for reverse indexing,
	// where [-1] means the last value, [-2] means the value before that, etc.
	T operator[](const int index)
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

	XORLinkedListIterator<T> iter()
	{
		return XORLinkedListIterator<T>(this->__list_handle.get_first());
	}

	XORLinkedListIterator<T> reverse_iter()
	{
		return XORLinkedListIterator<T>(this->__list_handle.get_last());
	}
};
