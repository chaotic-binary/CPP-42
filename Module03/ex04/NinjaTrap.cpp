#include "NinjaTrap.hpp"

NinjaTrap::~NinjaTrap(void) {
    std::cout << "\nYou was a good soldier, ";
    _printLog();
    std::cout << std::endl;
}

NinjaTrap::NinjaTrap(void) : ClapTrap(NNJmodel) {
    std::cout << "Default NinjaTrap came to this World!\n";
}

NinjaTrap::NinjaTrap(const std::string & name) : \
    ClapTrap(name, NNJmodel, 60, 60, 120, 120, 1, 60, 5, 0) {
    _printLog();
    std::cout << ": You can't see me, but I'm near!\n";
}

NinjaTrap::NinjaTrap(NinjaTrap const & src) : ClapTrap(src) {
    std::cout << "This is a clone of NinjaTrap!\n";
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & rhs) {
    NinjaTrap lhs = NinjaTrap(rhs);
    return (*this);
}

void NinjaTrap::ninjaShoebox(ClapTrap const & target) const {
    const std::string attacks[] = {	"Kuji-kiri",
                                    "Tensa Zangetsu",
                                    "Senbonzakura Kageyoshi",
                                    "Sode no Shirayuki",
                                    "Kannonbiraki Benihime Aratame" };

    std::cout << std::endl;
    if (&target == this)
        std::cout << "Harakiri!\n";
    else if (target.getModel() == this->getModel())
        std::cout << "Oh, brother! What about friendly fight?\n";

    if (target.getModel() == NNJmodel)
        std::cout << "Ninjas are power!\n";
    else if (target.getModel() == SCmodel)
        std::cout << "Hi, old iron thing! Fight?\n";
    else if (target.getModel() == FRmodel)
        std::cout << "FR4G-TP is such a cool model! Let's have fun!\n";
    else if (target.getModel() == SPmodel)
        std::cout << "You are shining so bright, SuperTrap!\n";
    else
        std::cout << "Hey, newcomer?\n";

    _printLog();
    std::cout << " is shoeboxing ";
    if (&target == this)
        std::cout << "himself\n";
    else
        std::cout << target.getModel() << " " << target.getName() << std::endl;
    unsigned int i = std::rand() % 5;
    std::cout << attacks[i] << std::endl;
}

