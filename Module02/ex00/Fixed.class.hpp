#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const & copy);
		~Fixed(void);

		Fixed &	operator=(Fixed const & rhs);

		void	setRawBits(int const raw);
		int		getRawBits(void) const;

	private:
		int					_value;
		static const int	_fractBits;
};

#endif