#include "serialize.hpp"

int main()
{
	void	*raw;
	Data	*data;

	srand(time(0));

	raw = serialize();
	data = deserialize(raw);
	std::cout << "\nDeserialized data:" << std::endl;
	std::cout << "s1 : " << data->s1 << "\nn  : " << data->n << "\ns2 : " << data->s2 << std::endl;
	delete data;
	return (0);
}
