#include "Utils.h"

#include <cstdint>

template <T>
std::intptr_t to_intptr(T* ptr) {
	return reinterpret_cast<std::intptr_t>(ptr);
}

template <T>
T* to_ptr(std::intptr_t intptr) {
	return reinterpret_cast<T*>(intptr);
}