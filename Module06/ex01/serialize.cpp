#include "serialize.hpp"

void	*serialize(void)
{
	const char		alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	Data			*data = new Data;

	for (int i = 0 ; i < 8 ; i++)
	{
		data->s1 += alphanum[std::rand() % 62];
		data->s2 += alphanum[std::rand() % 62];
	}
	data->n = std::rand();

	std::cout << "\nThe serialized data:" << std::endl;
	std::cout << "s1 : " << data->s1 << std::endl;
	std::cout << "n  : " << data->n << std::endl;
	std::cout << "s2 : " << data->s2 << std::endl;

	return (reinterpret_cast<void *>(data));
}

Data	*deserialize(void *void_data)
{
	return (reinterpret_cast<Data *>(void_data));
}
