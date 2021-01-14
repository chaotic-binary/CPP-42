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

void	NinjaTrap::rangedAttack(std::string const &target) const {
	ClapTrap::rangedAttack(target);
	std::cout << "Bankai!!\n\n";
}

void	NinjaTrap::meleeAttack(std::string const &target) const {
	ClapTrap::meleeAttack(target);
	std::cout << "Ninjaaaaaaa!!\n\n";
}

void NinjaTrap::ninjaShoebox(ClapTrap const & target) const {
	std::cout << "\nHey, newcomer?\n";
	shoeboxAttackMessage(target);
}

void NinjaTrap::ninjaShoebox(FragTrap const & target) const {
	std::cout << "\nHi, old iron thing!\n";
	shoeboxAttackMessage(target);
}

void NinjaTrap::ninjaShoebox(ScavTrap const & target) const {
	std::cout << "\nWow, ScavTraps are not extinct!\n";
	shoeboxAttackMessage(target);
}

void NinjaTrap::ninjaShoebox(NinjaTrap const & target) const {

	std::cout << std::endl;
	if (&target == this)
		std::cout << "Let's practice harakiri!\n";
	else
		std::cout << "Oh, brother!\n";
	shoeboxAttackMessage(target);
}

void NinjaTrap::shoeboxAttackMessage(ClapTrap const & target) const
{
	const std::string attacks[] = {	"Kuji-kiri",
								"Tensa Zangetsu",
								"Senbonzakura Kageyoshi",
								"Sode no Shirayuki",
								"Kannonbiraki Benihime Aratame" };

	_printLog();
	std::cout << " is shoeboxing ";
	if (&target == this)
		std::cout << "himself\n";
	else
		std::cout << modelId[target.getModel()] << " " << target.getName() << std::endl;
	unsigned int i = std::rand() % 5;
	std::cout << attacks[i] << std::endl;
}