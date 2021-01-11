#include "serialize.hpp"

int main()
{
	void	*raw;
	Data	*data;

	srand(time(0));

	raw = serialize();
	data = deserialize(raw);
	std::cout << "\nDeserialized data:" << std::endl;
	print_data(data);
	delete data;
	return (0);
}
