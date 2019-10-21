#pragma once

template <T>
std::intptr_t to_intptr(T* ptr);

template <T>
T* to_ptr(std::intptr_t intptr);