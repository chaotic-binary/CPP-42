#include <iostream>
#include <string>

int main(int argc, char **argv) {
	if (argc <= 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; ++i) {
		std::string s = argv[i];
		for (uint j = 0; j < s.size(); ++j)
			s[j] = toupper(s[j]);
		std::cout << s;
	}
	std::cout << std::endl;
	return (0);
}