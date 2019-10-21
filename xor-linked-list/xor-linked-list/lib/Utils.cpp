#include <cstdint>

#include "Utils.h"


std::intptr_t to_intptr(XorLinkedNode* ptr) {
	return reinterpret_cast<std::intptr_t>(ptr);
}

XorLinkedNode* to_ptr(std::intptr_t &intptr) {
	return reinterpret_cast<XorLinkedNode*>(intptr);
}