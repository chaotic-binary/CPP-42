#include "Brain.hpp"

Brain::Brain(void) {}
Brain::~Brain(void) {}

std::string Brain::identify(void) const
{
	std::stringstream ss;

	ss << (void *)this;
	return ss.str();
}