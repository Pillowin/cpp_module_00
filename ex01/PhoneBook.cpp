/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:25:58 by agautier          #+#    #+#             */
/*   Updated: 2021/11/11 12:00:16 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"
#include "PhoneBook.hpp"

/*
**	Default constructor.
*/
PhoneBook::PhoneBook(void) { this->_index = 0; }

/*
**	Destructor.
*/
PhoneBook::~PhoneBook(void) {}

/*
**	Listen in stdin for a command.
*/
bool PhoneBook::get_cmd(void) {
	std::string cmd;

	std::cout << "Please type a command: ADD, EXIT or SEARCH" << std::endl;
	if (!std::getline(std::cin, cmd)) {
		std::cerr << "exit" << std::endl;
		return (false);
	}
	if (cmd == "ADD")
		return (this->_cmd_add());
	else if (cmd == "EXIT")
		return (this->_cmd_exit());
	else if (cmd == "SEARCH")
		return (this->_cmd_search());
	return (this->_cmd_unknow());
}

/*
**	ADD command.
*/
bool PhoneBook::_cmd_add(void) {
	std::string info[5];
	std::string msg[5] = {"First name: ",
						  "Last name: ",
						  "Nickname: ",
						  "Phone number: ",
						  "Darkest secret: "};

	if (this->_index == 8) {
		std::cout << "The contact list full." << std::endl;
		return (true);
	}
	for (uint8_t i = 0; i < 5; i++) {
		std::cout << msg[i];
		if (!std::getline(std::cin, info[i])) {
			std::cerr << "exit" << std::endl;
			return (false);
		}
	}
	this->_contacts[this->_index] = Contact(info);
	this->_index += 1;
	return (true);
}

/*
**	EXIT command.
*/
bool PhoneBook::_cmd_exit(void) const { return (false); }

/*
**	SEARCH command.
*/
bool PhoneBook::_cmd_search(void) {
	uint8_t index = UINT8_MAX;
	std::string s;

	if (!this->_index) {
		std::cerr << "Contact list is empty." << std::endl;
		return (true);
	}
	std::cout << "|-----index|first name|-last name|--nickname|" << std::endl;
	for (uint8_t i = 0; i < this->_index; i++)
		this->_contacts[i].print_brief_infos(i);
	while (index >= this->_index) {
		std::cout << "Please type an index." << std::endl;
		if (!getline(std::cin, s)) {
			std::cerr << "exit" << std::endl;
			return (false);
		}
		if (s.length() == 1)
			index = s.at(0) - '0';
	}
	this->_contacts[index].print_infos();
	return (true);
}

/*
**	UNKNOW command.
*/
bool PhoneBook::_cmd_unknow(void) const {
	std::cout << "Unknow command." << std::endl;
	return (true);
}
