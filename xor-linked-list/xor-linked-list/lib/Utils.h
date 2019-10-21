#pragma once
#include "XorLinkedNode.h"

std::intptr_t to_intptr(XorLinkedNode* ptr);

XorLinkedNode* to_ptr(std::intptr_t intptr);