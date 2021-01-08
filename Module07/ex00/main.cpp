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
	int i1 = 1, i2 = 2;
	test_template(i1, i2);

	std::string s1 = "str1";
	std::string s2 = "str2";
	test_template(s1, s2);

	std::string s3 = "str3";
	std::string s4 = "str3";
	test_template(s3, s4);

	double d1 = 0.1, d2 = 0.2;
	test_template(d1, d2);
	return (0);

	char a = 'a', b = 'b';
	test_template(a, b);
}