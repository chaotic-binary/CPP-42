#include "Array.hpp"

int			main(void)
{
	std::cout << "Int array test:\n";
	Array<int> intArr1;
	Array<int> intArr2(5);
	intArr1 = intArr2;
	for (size_t i = 0; i < intArr1.size(); i++)
	{
		intArr1[i] = i;
		std::cout << intArr1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "\nStr array test:\n";
	Array<std::string> strArr2(2);
	strArr2[0] = "one";
	strArr2[1] = "two";
	Array<std::string> strArr(strArr2);
	for (size_t i = 0; i < strArr.size(); i++)
		std::cout << strArr[i] << " ";
	std::cout << std::endl;
	
	std::cout << "\nsize() test: " << strArr.size() << std::endl;

	std::cout << "\nOut of the bound test:\n";
	try {
		std::cout << strArr[strArr.size()] << std::endl;
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
