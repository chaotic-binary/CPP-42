#include "Array.hpp"

int			main(void)
{
	std::cout << "Empty array test:\n";
	Array<int> empty;
	std::cout << "size: " << empty.size() << std::endl;

	std::cout << "\nInt array test:\n";
	Array<int> intArr1(2);
	std::cout << "size: " << intArr1.size() << std::endl;
	Array<int> intArr2(5);
	intArr1 = intArr2;
	std::cout << "size: " << intArr1.size() << std::endl;
	for (uint i = 0; i < intArr1.size(); i++)
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
	for (uint i = 0; i < strArr.size(); i++)
		std::cout << strArr[i] << " ";
	std::cout << std::endl;
	std::cout << "size: " << strArr.size() << std::endl;

	std::cout << "\nOut of the bound test:\n";
	try {
		std::cout << strArr[strArr.size()] << std::endl;
	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
