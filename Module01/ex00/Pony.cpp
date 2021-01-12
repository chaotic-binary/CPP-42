#include "Pony.hpp"

Pony::Pony(std::string name, std::string color) : _name(name), _color(color) {
	this->_is_laughing = 0;
	this->_is_sleeping = 0;
	std::cout << "Say Hi to Pony " << name << "!\n";
}

Pony::~Pony(void) {
	std::cout << "Pony " << this->_name << " is gone\n";
}

const std::string& Pony::getName() const {
	return (this->_name);
}

const std::string& Pony::getColor() const {
	return (this->_color);
}

bool Pony::getSleepingState() const {
	return (this->_is_sleeping);

}
bool Pony::getLaughingState() const {
	return (this->_is_laughing);
}

void Pony::setSleepingState(bool state) {
	this->_is_sleeping = state;
	if (this->_is_sleeping)
		std::cout << this->_name << ": zzz~\n";
}

void Pony::setLaughingState(bool state) {
	this->_is_laughing = state;
	if (this->_is_laughing)
		std::cout << this->_name << ": ahahahaha~\n";
}

void Pony::check_on_pony() const {
	std::cout << this->_name << " is " << this->_color;
	std::cout << " and now it's ";
	(this->_is_laughing) ? std::cout << "laughing\n" : std::cout << "serious\n";
	if (this->_is_sleeping)
		std::cout << "Shh! It's sleeping!\n";
}