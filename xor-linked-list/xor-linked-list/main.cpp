#include <iostream>

int main()
{
	int a = 0;
	int b = 1;
	int* a_ptr = &a;
	int* b_ptr = &b;

	int* x_ptr = a_ptr ^ b_ptr;

	std::cout << x_ptr << std::endl;
}
