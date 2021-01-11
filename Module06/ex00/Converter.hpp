#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>

enum ConversionStatus {
	ConvertibleToDouble = 1,
	ConvertibleToFloat = 2,
	ConvertibleToInt = 4,
	ConvertibleToChar = 8
};

class Converter
{
public:

	Converter(std::string const &);
	Converter(const Converter &copy);
	~Converter();
	Converter &operator=(const Converter &copy);

	double	d;
	float	f;
	int		i;
	char	c;

	bool checkConversionStatus(int convertionStatus) const;

private:
	Converter();

	bool isChar(std::string const &) const;
	bool isInt(std::string const &) const;
	bool isFloat(std::string const &) const;
	bool isDisplayable(char c) const;

	void fromChar(char c);
	void fromNumStr(std::string const &);
	void fromNotNumStr(std::string const &);

	int _success;
};

std::ostream &operator<<(std::ostream &os, Converter const & converter);

#endif
