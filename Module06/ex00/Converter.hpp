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

	void printResult() const;

private:
	Converter();

	bool isChar(std::string const &) const;
	bool isInt(std::string const &) const;
	bool isFloat(std::string const &) const;
	bool isSpecialDouble(std::string const &) const;
	bool isSpecialFloat(std::string const &) const;
	bool isDisplayable(char c) const;

	void fromChar(char c);
	void fromNumStr(std::string const &);
	void fromNotNumStr(std::string const &);

	bool checkConversionStatus(int convertionStatus) const;

	double	_d;
	float	_f;
	int		_i;
	char	_c;
	int		_success;
};

#endif
