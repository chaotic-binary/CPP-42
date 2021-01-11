#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <set>

class Span
{
public:
	Span();
	Span(uint size);
	Span(const Span &copy);
	~Span();
	Span &operator=(const Span &copy);

	void	addNumber(int);
	uint	shortestSpan(void) const;
	uint	longestSpan(void) const;

	class NoRoomException: public std::exception
	{
		virtual const char* what() const throw();
	};
	class NoSpanException: public std::exception
	{
		virtual const char* what() const throw();
	};

private:
	uint				_maxN;
	std::multiset<int>	_numbers;
	void				_check_N() const;
};

#endif
