#ifndef ID_HPP
# define ID_HPP

# include <iostream>

class Base
{
	public:
		virtual ~Base(void);
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate(void);
void identify_from_pointer(Base *p);
void identify_from_reference(Base &b);

#endif
