#include "ScavTrap.hpp"

ScavTrap::~ScavTrap(void) {
    std::cout << "\nTime to say goodbye to SC4V-TP " << getName() << std::endl;
}

ScavTrap::ScavTrap(void) {}

ScavTrap::ScavTrap(const std::string name) : \
     ClapTrap(name, "SC4V-TP", 100, 100, 50, 50, 1, 20, 15, 3) {
    _printLog();
    std::cout << " is our new player!\n";
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src) {
    std::cout << "This is a clone of ScavTrap!\n";
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs) {
    ScavTrap lhs = ScavTrap(rhs);
    return (*this);
}

void	ScavTrap::challengeNewcomer(std::string const & target) const
{
    const std::string challenges[] = {	"Let's see are you worthy, Newcomer! Can you exit Vim?",
                                         "I want free samples of your inner demons. Now!",
                                         "I need to eat an entire snowman! Hurry up!",
                                         "Find me a box within a box filled with cute tiny boxes.",
                                         "Tell me a joke, Newcomer! If you make me smile, I let you pass." };

    std::cout << std::endl;
    _printLog();
    std::cout << " challenged " << target << " with this task:\n";
    std::cout << challenges[std::rand() % 5] << std::endl;
}