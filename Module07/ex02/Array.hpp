#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
public:
	Array();
	Array(size_t n);
	Array(const Array &copy);
	~Array();
	Array &operator=(const Array &copy);

	class OutOfBoundsException: public std::exception
	{
		virtual const char* what() const throw();
	};

	size_t size() const;
	T &operator[](size_t i) const;

private:
	T*		_arr;
	size_t	_size;
	void	_deepCopy(const Array &copy);
	void	_delArr();
};

# include "Array.ipp"
#endif

