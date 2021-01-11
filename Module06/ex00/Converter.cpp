#include "Converter.hpp"

Converter::Converter() {}

Converter::Converter(std::string const & str) \
	: _success(0), _d(0), _f(0), _i(0), _c(0)
{
	if (isChar(str))
		fromChar(str[0]);
	else if (isInt(str) || isFloat(str))
		fromNumStr(str);
	else if (isSpecialDouble(str))
		fromNotNumStr(str);
	else if (isSpecialFloat(str))
	{
		std::string str_copy = str;
		str_copy.erase(str.size() - 1);
		fromNotNumStr(str_copy);
	}
}

Converter::~Converter() {}

Converter::Converter(const Converter &copy)
	: _d(copy._d), _f(copy._f), _i(copy._i), _c(copy._c), \
	_success(copy._success)
{}

Converter	&Converter::operator=(const Converter &copy)
{
	if (this == &copy)
		return (*this);
	this->_d = copy._d;
	this->_f = copy._f;
	this->_i = copy._i;
	this->_c = copy._c;
	this->_success = copy._success;
	return (*this);
}

bool Converter::isChar(std::string const & str) const
{
	return (str.size() == 1 && !isdigit(str[0]));
}

bool Converter::isInt(std::string const &str) const
{
	int i;

	i = 0;
	//while (isspace(str[i++]))
	//	++i;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i++])
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool Converter::isFloat(std::string const &str) const
{
	int i;
	int dot;

	i = 0;
	dot = 0;
	//while (isspace(str[i++]))
	//	++i;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i])
	{
		if (isdigit(str[i]))
			++i;
		else if (str[i] == '.' && !dot)
		{
			++i;
			dot = 1;
		}
		else if (str[i] == 'f' && !str[i + 1])
			return true;
		else
			return false;
	}
	return (true);
}

bool Converter::isSpecialDouble(std::string const &str) const
{
	return (str == "nan" || str == "inf" || str == "-inf" || str == "+inf");
}

bool Converter::isSpecialFloat(std::string const &str) const
{
	return (str == "nanf" || str == "inff" ||  str == "-inff" ||  str == "+inff");
}

bool Converter::isDisplayable(char c) const
{
	return (c > 32 && c < 127);
}

void Converter::fromChar(char c)
{
	this->_c = c;
	this->_i = static_cast<int>(c);
	this->_d = static_cast<double>(c);
	this->_f = static_cast<float>(c);
	this->_success = this->_success | ConvertibleToChar | ConvertibleToInt | ConvertibleToFloat | ConvertibleToDouble;
}

void Converter::fromNotNumStr(std::string const & str)
{
	std::istringstream ss(str);
	ss >> this->_d;
	if (this->_d != 0)
	{
		this->_f = static_cast<float>(_d);
		this->_success = this->_success | ConvertibleToDouble | ConvertibleToFloat;
	}
}

void Converter::fromNumStr(std::string const & str)
{
	try {
		this->_d = std::stod(str);
		this->_success |= ConvertibleToDouble;
		this->_f = std::stof(str);
		this->_success |= ConvertibleToFloat;
		this->_i = std::stoi(str);
		this->_success |= ConvertibleToInt;
		if (_i >= std::numeric_limits<char>::min() && _i < std::numeric_limits<char>::max())
		{
			this->_c = static_cast<char>(_i);
			this->_success |= ConvertibleToChar;
		}
	} catch (const std::exception &e) {}
}

bool Converter::checkConversionStatus(int convertionStatus) const
{
	if (!(this->_success & convertionStatus))
	{
		std::cout << "impossible\n";
		return false;
	}
	else if (convertionStatus == ConvertibleToChar && !isDisplayable(this->_c))
	{
		std::cout << "Non displayable\n";
		return false;
	}
	return true;
}

void Converter::printResult() const
{
	std::cout << "char: ";
	if (checkConversionStatus(ConvertibleToChar))
		std::cout << _c << std::endl;
	std::cout << "int: ";
	if (checkConversionStatus(ConvertibleToInt))
		std::cout << _i << std::endl;
	std::cout << "float: ";
	if (checkConversionStatus(ConvertibleToFloat))
		std::cout << std::setprecision(1) << std::fixed << _f << "f" << std::endl;
	std::cout << "double: ";
	if (checkConversionStatus(ConvertibleToDouble))
		std::cout << std::setprecision(1) << std::fixed << _d << std::endl;
}