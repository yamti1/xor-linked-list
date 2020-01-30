#include "XORLinkedNode.h"


class XORLinkedListIterator {
	class __Iterator {
	private:
		// TODO: What should happen with these on delete?
		XORLinkedNode* __current_node;
		XORLinkedNode* __prev_node;

	public:
		__Iterator(XORLinkedNode* const first);

		void operator++();
		int operator*();
		bool operator==(const __Iterator& other);
		bool operator!=(const __Iterator& other);
	};

private:
	__Iterator __iterator;

public:
	XORLinkedListIterator(XORLinkedNode* const first);
	
	__Iterator begin();
	__Iterator end();
};