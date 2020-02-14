#pragma once
#include <cstdint>

template <class T>
class XORLinkedNode
{
private:
	std::intptr_t __both;
	int __value;

public:
	XORLinkedNode(T value, XORLinkedNode<T>* prev, XORLinkedNode<T>* next) {
		this->__value = value;
		this->set_both(prev, next);
	}

	XORLinkedNode<T>* get_next_or_prev(XORLinkedNode<T>* other);

	void set_both(XORLinkedNode<T>* prev, XORLinkedNode<T>* next);

	T get_value() { return this->__value; }
	void set_value(T value) { this->__value = value; }
};


template <class T>
std::intptr_t to_intptr(XORLinkedNode<T>* ptr) {
	return reinterpret_cast<std::intptr_t>(ptr);
}

template <class T>
XORLinkedNode<T>* to_ptr(std::intptr_t intptr) {
	return reinterpret_cast<XORLinkedNode<T>*>(intptr);
}

template <class T>
XORLinkedNode<T>* XORLinkedNode<T>::get_next_or_prev(XORLinkedNode<T>* other) {
	return to_ptr<T>(to_intptr<T>(other) ^ this->__both);
}

template <class T>
void XORLinkedNode<T>::set_both(XORLinkedNode<T>* prev, XORLinkedNode<T>* next) {
	this->__both = to_intptr<T>(next) ^ to_intptr<T>(prev);
}
