#include "NinjaTrap.hpp"

NinjaTrap::~NinjaTrap(void) {
	std::cout << "\nYou was a good soldier, ";
	_printLog();
	std::cout << std::endl;
}

NinjaTrap::NinjaTrap(void) : ClapTrap(NN) {
	std::cout << "Default NinjaTrap came to this World!\n";
}

NinjaTrap::NinjaTrap(const std::string & name) : \
	ClapTrap(name, NN, 60, 60, 120, 120, 1, 60, 5, 0) {
	_printLog();
	std::cout << ": You can't see me, but I'm near!\n";
}

NinjaTrap::NinjaTrap(NinjaTrap const & src) : ClapTrap(src) {
	std::cout << "This is a clone of NinjaTrap!\n";
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & rhs) {
	ClapTrap::operator=(rhs);
	return (*this);
}

void	NinjaTrap::meleeAttack(std::string const &target) const {
	ClapTrap::meleeAttack(target);
	std::cout << "Ninjaaaaaaa!!\n\n";
}

void NinjaTrap::ninjaShoebox(ClapTrap const & target) const {
	const std::string attacks[] = {	"Kuji-kiri",
									"Tensa Zangetsu",
									"Senbonzakura Kageyoshi",
									"Sode no Shirayuki",
									"Kannonbiraki Benihime Aratame" };

	std::cout << std::endl;
	unsigned char targetModel = target.getModel();
	if (&target == this)
		std::cout << "Harakiri!\n";
	else if (targetModel == this->getModel())
		std::cout << "Oh, brother! What about friendly fight?\n";

	switch(targetModel) {
		case NN:
			std::cout << "Ninjas are power!\n";
			break;
		case SC:
			std::cout << "Hi, old iron thing! Fight?\n";
			break;
		case FR:
			std::cout << "FR4G-TP is such a cool model! Let's have fun!\n";
			break;
		case SP:
			std::cout << "You are shining so bright, SuperTrap!\n";
			break;
		default:
			std::cout << "Hey, newcomer?\n";
			break;
	}

	_printLog();
	std::cout << " is shoeboxing ";
	if (&target == this)
		std::cout << "himself\n";
	else
		std::cout << modelId[targetModel] << " " << target.getName() << std::endl;
	unsigned int i = std::rand() % 5;
	std::cout << attacks[i] << std::endl;
}

