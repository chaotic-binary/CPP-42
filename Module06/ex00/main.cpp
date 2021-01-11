#include "Converter.hpp"

static void trim_str(std::string &str)
{
	str.erase(0, str.find_first_not_of(' '));
	str.erase(str.find_last_not_of(' ') + 1);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "One argument required" << std::endl;
		return (0);
	}
	std::string str = av[1];
	trim_str(str);
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	Converter converter(str);
	std::cout << converter;
	return (0);
}
