#include "whatever.hpp"

template <typename T>
void test_template(T &a, T &b)
{
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After swap:\n";
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl << std::endl;
}

int main(void)
{
	{
		int a = 1, b = 2;
		test_template(a, b);
	}
	{
		std::string s1 = "str1";
		std::string s2 = "str2";
		test_template(s1, s2);
	}
	{
		std::string s1 = "str3";
		std::string s2 = "str3";
		test_template(s1, s2);
	}
	{
		double a = 0.1, b = 0.2;
		test_template(a, b);
	}
	{
		char a = 'a', b = 'b';
		test_template(a, b);
	}
	return (0);
}