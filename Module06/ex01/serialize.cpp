#include "serialize.hpp"

void	*serialize(void)
{
	const char		symbols[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	Data			*data = new Data;

	for (int i = 0 ; i < 8 ; i++)
	{
		data->s1 += symbols[std::rand() % 62];
		data->s2 += symbols[std::rand() % 62];
	}
	data->n = std::rand();

	std::cout << "\nSerialized data:" << std::endl;
	std::cout << "s1 : " << data->s1 << "\nn  : " << data->n << "\ns2 : " << data->s2 << std::endl;

	return (reinterpret_cast<void *>(data));
}

Data	*deserialize(void *raw)
{
	return (reinterpret_cast<Data *>(raw));
}
