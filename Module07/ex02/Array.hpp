#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

typedef	unsigned int	uint;

template <typename T>
class Array
{
public:
	Array();
	Array(uint n);
	Array(const Array &copy);
	~Array();
	Array &operator=(const Array &copy);

	class OutOfBoundsException: public std::exception
	{
		virtual const char* what() const throw();
	};

	uint size() const;
	T &operator[](uint i) const;

private:
	T*		_arr;
	uint	_size;
	void	_deepCopy(const Array &copy);
	void	_delArr();
};

# include "Array.ipp"
#endif

