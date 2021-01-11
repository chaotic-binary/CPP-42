#include "Converter.hpp"

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "One argument required" << std::endl;
		return (0);
	}
	std::string str = av[1];
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	Converter converter(str);
	std::cout << converter;
	return (0);
}
