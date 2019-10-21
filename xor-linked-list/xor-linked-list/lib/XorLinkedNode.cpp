#include "XorLinkedNode.h"
#include "Utils.h"

XorLinkedNode::XorLinkedNode(int value, XorLinkedNode* next, XorLinkedNode* prev) {
	this->__value = value;
	this->set_both(prev, next);
}

XorLinkedNode* XorLinkedNode::get_next_or_prev(XorLinkedNode* other) {
	return to_ptr(to_intptr(other) ^ this->__both);
}

void XorLinkedNode::set_both(XorLinkedNode* prev, XorLinkedNode* next) {
	this->__both = to_intptr(next) ^ to_intptr(prev);
}