#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>
#include <cmath>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const & copy);
		~Fixed(void);

		Fixed&	operator=(Fixed const & rhs);
		
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_value;
		static const int	_fractBits;
};

std::ostream &operator<<(std::ostream &os, Fixed const &in);

#endif