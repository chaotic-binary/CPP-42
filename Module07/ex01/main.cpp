
#include "iter.hpp"

template <typename T>
void iter(T *arr, size_t len, void (*func)(T const &)) {
	for (size_t i = 0; i < len; ++i)
		func(arr[i]);
}

static void	print_element(const int &a)
{
	std::cout << a << std::endl;
}

int main(void)
{
	int arr[4] = {0, 1, 2, 3};

	iter(arr, 4, print_element);
}