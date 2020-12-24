#include "phonebook.hpp"

	int	Contact::_contats_count = 0;

	const std::string	Contact::_fieldnames[FIELDS_NUM] = {"index",
															"first name",
															"last name",
															"nickname",
															"login",
															"postal address",
															"e-mail address",
															"phone number",
															"birthday date",
															"favorite meal",
															"underwear color",
															"darkest secret"};

	Contact::Contact(void) { }
	Contact::~Contact(void) { }

	int	Contact::getContactCount(void)  { return (Contact::_contats_count); }

	void	Contact::CreateContact(void) {
		this->_contact_entries[0] = std::to_string(++Contact::_contats_count);
		for (int i = 1; i < FIELDS_NUM; i++) {
			std::cout << Contact::_fieldnames[i] << ": ";
			if (!(std::cin >> this->_contact_entries[i]))
				error_exit();
		}
	}

	static std::string truncated_str(const std::string &s) {
		std::string res;

		res = s;
		res.replace(9, 1, ".");
		res.erase(WIDTH, s.length() - WIDTH);
		return (res);
	}

	static void	PrintValues(const std::string values[], bool istitle){
		for (int i = 0; i < 4; i++) {
			if (i > 0)
				std::cout << "|";
			std::cout << std::setw(WIDTH) << ((istitle || values[i].size() < WIDTH) ? values[i] : truncated_str(values[i]));
		}
		std::cout << std::endl;
	}

	void	Contact::PrintContactPreview(const int count) const {
		if (count == 0)
			PrintValues(Contact::_fieldnames, 1);
		PrintValues(this->_contact_entries, 0);
	}

	void	Contact::PrintContactFull(void) const {
		for (int i = 1; i < FIELDS_NUM; i++) {
			std::cout << Contact::_fieldnames[i] << ": ";
			std::cout << this->_contact_entries[i] << std::endl;
		}
	}
