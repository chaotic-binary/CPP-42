#include "phonebook.hpp"

void	error_exit() {
	std::cerr << "Input error!\n";
	exit(1);
}

static int	index_search(void) {
	int n = 0;
	std::string input;

	std::cout << "Enter the index of the desired entry\n";
	if (!(std::getline(std::cin, input)))
		error_exit();
	try {
		n = stoi(input);
	} catch(std::exception &err) {
		std::cerr << "Error! Wrong input, do SEARCH again\n";
		return (-1);
	}
	if (n < 1 || n > Contact::getContactCount()) {
		std::cerr << "Error! Index is incorrect, do SEARCH again!\n";
		return (-1);
	}
	return (n - 1);
}

int	main(void) {
	std::cout << "Welcome to the PhoneBook!\n";
	std::cout << "Commands:\n";
	std::cout << "ADD (you can add up to " << CAPACITY << " contacts)" << std::endl;
	std::cout << "SEARCH\n";
	std::cout << "EXIT\n\n";
	std::cout << "Your commands:\n";

	std::string cmd;
	Contact contacts[8];
	Contact entry;
	int n;

	while (std::getline(std::cin, cmd)) {
		if (cmd == "EXIT")
			break ;
		else if (cmd == "ADD") {
			if (Contact::getContactCount() == CAPACITY)
				std::cout << "Phonebook is full!\n";
			else {
				entry.CreateContact();
				contacts[Contact::getContactCount() - 1] = entry;
			}
		}
		else if (cmd == "SEARCH") {
			if (Contact::getContactCount() == 0) {
				std::cout << "Phonebook is empty!\n";
				continue ;
			}
			for (int i = 0; i < Contact::getContactCount(); i++) {
				contacts[i].PrintContactPreview(i);
			}
			if ((n = index_search()) >= 0) {
                contacts[n].Contact::PrintContactFull();
            }
		}
	}
	return (0);
}