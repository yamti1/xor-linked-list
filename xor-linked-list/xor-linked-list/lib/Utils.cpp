#include <cstdint>

#include "Utils.h"


std::intptr_t to_intptr(XORLinkedNode* ptr) {
	return reinterpret_cast<std::intptr_t>(ptr);
}

XORLinkedNode* to_ptr(std::intptr_t intptr) {
	return reinterpret_cast<XORLinkedNode*>(intptr);
}