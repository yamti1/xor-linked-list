#include "XorLinkedNode.h"
#include "Utils.h"

XORLinkedNode::XORLinkedNode(int value, XORLinkedNode* prev, XORLinkedNode* next) {
	this->__value = value;
	this->set_both(prev, next);
}

XORLinkedNode* XORLinkedNode::get_next_or_prev(XORLinkedNode* other) {
	return to_ptr(to_intptr(other) ^ this->__both);
}

void XORLinkedNode::set_both(XORLinkedNode* prev, XORLinkedNode* next) {
	this->__both = to_intptr(next) ^ to_intptr(prev);
}

int XORLinkedNode::get_value() {
	return this->__value;
}

void XORLinkedNode::set_value(int value) {
	this->__value = value;
}