
#include "iter.hpp"

template <typename T>
static void	print_element(const T &a)
{
	std::cout << a << " ";
}

int main(void)
{
	{
		int arr[4] = {0, 1, 2, 3};
		iter(arr, 4, print_element);
	}
	std::cout << std::endl;
	{
		std::string arr[4] = {"zero", "one", "two", "three"};
		iter(arr, 4, print_element);
	}
}