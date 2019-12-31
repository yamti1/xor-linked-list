#include <cstdint>

#include "Utils.h"


std::intptr_t to_intptr(XORLinkedNode* ptr) {
	return reinterpret_cast<std::intptr_t>(ptr);
}

XORLinkedNode* to_ptr(std::intptr_t intptr) {
	return reinterpret_cast<XORLinkedNode*>(intptr);
}

void advance_node_ptrs(XORLinkedNode* current_node, XORLinkedNode* prev_node) {
	XORLinkedNode* tmp_node = current_node;
	current_node = current_node->get_next_or_prev(prev_node);
	prev_node = tmp_node;
}