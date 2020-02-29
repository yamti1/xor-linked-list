#include <iostream>
#include <exception>

#include "lib/XORLinkedList.h"

int main()
{
	int arr[] = { 1, 2, 3 };
	//XORLinkedList<int> list({ 1, 2, 3, 4, 5 });
	XORLinkedList<int> list(arr);

	for (int value : list.iter()) {
		std::cout << value << ", ";
	}

	std::cout << std::endl;

	for (int value : list.reverse_iter()) {
		std::cout << value << ", ";
	}


	std::cout << "list.get(1) = " << list.get(1) << std::endl;
	std::cout << "list.get_reverse(1) = " << list.get_reverse(1) << std::endl;

	std::cout << "list[1] = " << list[1] << std::endl;
	std::cout << "list[-2] = " << list[-2] << std::endl;

	XORLinkedList<std::string> str_list;
	str_list.add("One");
	str_list.add("Two");
	str_list.add("Three");

	for (std::string str : str_list.iter())
	{
		std::cout << str << ", ";
	}

	std::cout << str_list[2] << std::endl;
}