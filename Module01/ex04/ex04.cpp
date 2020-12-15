#include <iostream>
#include <string>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::cout << "String: " << str << std::endl;
	std::string* pointer = &str;
	std::cout << "Pointer: " << *pointer << std::endl;
	std::string& reference = str;
	std::cout << "Reference: " << reference << std::endl;
	return (0);
}