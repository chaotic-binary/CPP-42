#ifndef SQUAD_HPP
# define SQUAD_HPP

# include <iostream>
# include "ISquad.hpp"
# include "ISpaceMarine.hpp"

class	Squad : public ISquad
{
public:
	Squad();
	Squad(const Squad &copy);
	virtual ~Squad();
	Squad &operator=(const Squad &copy);

	virtual int				getCount() const;
	virtual ISpaceMarine*	getUnit(int) const;
	virtual int				push(ISpaceMarine*);

private:

	typedef struct			s_unitlist
	{
		ISpaceMarine		*unit;
		struct s_unitlist	*next;
	}						t_unitlist;

	int			_unitCount;
	t_unitlist	*_units;
	void		_deepCopy(const Squad &copy);
};

#endif
