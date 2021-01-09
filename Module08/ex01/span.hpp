#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <set>

class Span
{
public:
	Span();
	Span(size_t size);
	Span(const Span &copy);
	~Span();
	Span &operator=(const Span &copy);

	void	addNumber(int);
	size_t	shortestSpan(void) const;
	size_t	longestSpan(void) const;

	class NoRoomException: public std::exception
	{
		virtual const char* what() const throw();
	};
	class NoSpanException: public std::exception
	{
		virtual const char* what() const throw();
	};

private:
	size_t				_maxN;
	std::multiset<int>	_numbers;
	void				_check_N() const;
};

#endif
