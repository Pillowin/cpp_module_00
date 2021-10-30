/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:25:58 by agautier          #+#    #+#             */
/*   Updated: 2021/10/30 23:20:29 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"
#include "PhoneBook.hpp"

/*
**	Default constructor.
*/
PhoneBook::PhoneBook(void)
{
	this->index = 0;
}

/*
**	Destructor.
*/
PhoneBook::~PhoneBook(void)
{
}

/*
**	Listen in stdin for a command.
*/
bool	PhoneBook::get_cmd(void)
{
	std::string	cmd;

	std::cout
		<< "Please type a command: ADD, EXIT or SEARCH"
		<< std::endl;
	if (!std::getline(std::cin, cmd))
	{
		std::cerr << "exit" << std::endl;
		return (false);
	}
	if (cmd == "ADD")
		return (this->cmd_add());
	else if (cmd == "EXIT")
		return (this->cmd_exit());
	else if (cmd == "SEARCH")
		return (this->cmd_search());
	return (this->cmd_unknow());
}

/*
**	ADD command.
*/
bool	PhoneBook::cmd_add(void)
{
	std::string	info[5];
	std::string	msg[5] = {
		"First name: ",
		"Last name: ",
		"Nickname: ",
		"Phone number: ",
		"Darkest secret: "
	};

	if (this->index == 8)
	{
		std::cout << "The contact list full." << std::endl;
		return (true);
	}
	for (uint8_t i = 0; i < 5; i++)
	{
		std::cout << msg[i];
		if (!std::getline(std::cin, info[i]))
		{
			std::cerr << "exit" << std::endl;
			return (false);
		}
	}
	this->contacts[this->index] = Contact(info);
	this->index += 1;
	return (true);
}

/*
**	EXIT command.
*/
bool	PhoneBook::cmd_exit(void) const
{
	return (false);
}

/*
**	SEARCH command.
*/
bool	PhoneBook::cmd_search(void)
{
	uint32_t	index = UINT32_MAX;
	std::string	s;

	if (!this->index)
	{
		std::cerr << "Contact list is empty." << std::endl;
		return (true);
	}
	std::cout << "|-----index|first name|-last name|--nickname|" << std::endl;
	for (uint8_t i = 0; i < this->index; i++)
		this->contacts[i].print_brief_infos(i);
	while (index >= this->index)
	{
		std::cout << "Please type an index." << std::endl;
		if (!std::getline(std::cin, s))
		{
			std::cerr << "exit" << std::endl;
			return (false);
		}
		try {
			index = std::stoul(s);
		} catch (const std::invalid_argument e) {
			continue ;
		}
	}
	this->contacts[index].print_infos();
	return (true);
}

/*
**	UNKNOW command.
*/
bool	PhoneBook::cmd_unknow(void) const
{
	std::cout << "Unknow command." << std::endl;
	return (true);
}
