#include "XORLinkedNode.h"
#include "XORLinkedListHandle.h"

// Iterates on a XORLinkedList according to the Iterator protocol in C++
template <class T>
class XORLinkedListIterator {
	// The underlying iterator
	class __Iterator {
	private:
		// TODO: What should happen with these on delete?
		XORLinkedNode<T>* __current_node;
		XORLinkedNode<T>* __prev_node;

	public:
		__Iterator(XORLinkedNode<T>* const first) :
			__current_node(first),
			__prev_node(nullptr)
		{}

		void operator++() {
			advance_node_ptrs<T>(this->__current_node, this->__prev_node);
		}

		T operator*() {
			return this->__current_node->get_value();
		}

		bool operator==(const __Iterator<T>& other) {
			// This causes the iteration to stop because `other` is the `end` iterator which has __current_node of null.
			return this->__current_node == other.__current_node;
		}

		bool operator!=(const __Iterator<T>& other) {
			return !(*this == other);
		}
	};

private:
	__Iterator<T> __iterator;

public:
	XORLinkedListIterator(XORLinkedNode<T>* const first)
		: __iterator(first)
	{}
	
	__Iterator<T> begin() {
		return this->__iterator;
	}

	__Iterator<T> end() {
		return __Iterator(nullptr);
	}
};