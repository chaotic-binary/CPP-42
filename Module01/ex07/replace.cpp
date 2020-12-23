#include "replace.hpp"

static int	error_msg(int err_type)
{
	switch (err_type)
	{
		case ERR_ARG:
			std::cerr << "Invalid number of arguments: 3 required\n";
			break;
		case ERR_EMPTY:
			std::cerr << "Strings shouldn't be empty\n";
			break;
		case ERR_OPEN:
			std::cerr << "Error while opening the file\n";
			break;
		case ERR_CREATE:
			std::cerr << "Error while creating the file\n";
			break;
		default:
			std::cerr << "Error!\n";
			break;
	}
	return (-1);
}

int	main(int ac, char **av)
{
	std::string filename;
	std::string s1;
	std::string s2;
	std::string content;

	if (ac != 4)
		return (error_msg(ERR_ARG));
	if ((s1 = av[2]).empty() || (s2 = av[3]).empty())
		return (error_msg(ERR_EMPTY));
	std::ifstream ifs(filename = av[1]);
	if (!ifs)
		return (error_msg(ERR_OPEN));
	ifs.seekg(0,std::ios::end);
	std::streampos len = ifs.tellg();
	ifs.seekg(0,std::ios::beg);
	content.resize(len);
	ifs.read(&content[0],len);
	while (content.find(s1) != std::string::npos)
		content.replace(content.find(s1), s1.length(), s2);
	ifs.close();
	std::ofstream ofs(filename.append(".replace"));
	if (!ofs)
		return (error_msg(ERR_CREATE));
	ofs << content;
	ofs.close();
	return (0);
}