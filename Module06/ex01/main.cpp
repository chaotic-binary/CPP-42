#include "serialize.hpp"

int main()
{
	void	*serialized;
	Data	*data;

	srand(time(0));
	
	serialized = serialize();
	data = deserialize(serialized);
	std::cout << "\nThe deserialized data:" << std::endl;
	std::cout << "s1 : " << data->s1 << std::endl;
	std::cout << "n  : " << data->n << std::endl;
	std::cout << "s2 : " << data->s2 << std::endl;
	delete data;
	return (0);
}
