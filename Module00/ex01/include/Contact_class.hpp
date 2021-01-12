#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <string>
# include <iostream>
# include <iomanip>
# include "../include/phonebook.hpp"

#define FIELDS_NUM 12
#define WIDTH 10

class	Contact
{
	public:
		Contact(void);
		~Contact(void);

		void		CreateContact(void);
		void		PrintContactPreview(const int count) const;
		void		PrintContactFull(void) const;
		static int	getContactCount(void);

	private:
		std::string					_contact_entries[FIELDS_NUM];
		const static std::string	_fieldnames[FIELDS_NUM];
		static int					_contats_count;
};

#endif