#pragma once
#include "XorLinkedNode.h"

std::intptr_t to_intptr(XORLinkedNode* ptr);

XORLinkedNode* to_ptr(std::intptr_t intptr);

void advance_node_ptrs(XORLinkedNode* current_node, XORLinkedNode* prev_node);