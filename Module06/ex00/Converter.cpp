#include "Converter.hpp"

Converter::Converter() {}

Converter::Converter(std::string const & str) \
	: _success(0), d(0), f(0), i(0), c(0)
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
	: d(copy.d), f(copy.f), i(copy.i), c(copy.c), \
	_success(copy._success)
{}

Converter	&Converter::operator=(const Converter &copy)
{
	if (this == &copy)
		return (*this);
	this->d = copy.d;
	this->f = copy.f;
	this->i = copy.i;
	this->c = copy.c;
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
	this->c = c;
	this->i = static_cast<int>(c);
	this->d = static_cast<double>(c);
	this->f = static_cast<float>(c);
	this->_success = this->_success | ConvertibleToChar | ConvertibleToInt | ConvertibleToFloat | ConvertibleToDouble;
}

void Converter::fromNotNumStr(std::string const & str)
{
	std::istringstream ss(str);
	ss >> this->d;
	if (this->d != 0)
	{
		this->f = static_cast<float>(d);
		this->_success = this->_success | ConvertibleToDouble | ConvertibleToFloat;
	}
}

void Converter::fromNumStr(std::string const & str)
{
	try {
		this->d = std::stod(str);
		this->_success |= ConvertibleToDouble;
		this->f = std::stof(str);
		this->_success |= ConvertibleToFloat;
		this->i = std::stoi(str);
		this->_success |= ConvertibleToInt;
		if (i >= std::numeric_limits<char>::min() && i < std::numeric_limits<char>::max())
		{
			this->c = static_cast<char>(i);
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
	else if (convertionStatus == ConvertibleToChar && !isDisplayable(this->c))
	{
		std::cout << "Non displayable\n";
		return false;
	}
	return true;
}

std::ostream &operator<<(std::ostream &os, Converter const & converter)
{
	os << "char: ";
	if (converter.checkConversionStatus(ConvertibleToChar))
		os << converter.c << std::endl;
	os << "int: ";
	if (converter.checkConversionStatus(ConvertibleToInt))
		os << converter.i << std::endl;
	os << "float: ";
	if (converter.checkConversionStatus(ConvertibleToFloat))
		os << std::setprecision(1) << std::fixed << converter.f << "f" << std::endl;
	os << "double: ";
	if (converter.checkConversionStatus(ConvertibleToDouble))
		os << std::setprecision(1) << std::fixed << converter.d << std::endl;
	return (os);
}