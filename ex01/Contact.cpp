/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:32:55 by agautier          #+#    #+#             */
/*   Updated: 2021/11/05 15:58:02 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*
**	Default constructor.
*/
Contact::Contact(void)
{
}

/*
**	Constructor with parameters.
*/
Contact::Contact(std::string info[5]) :	_first_name(info[0]),
										_last_name(info[1]),
										_nickname(info[2]),
										_phone_number(info[3]),
										_darkest_secret(info[4])
{
}

/*
**	Destructor.
*/
Contact::~Contact(void)
{
}

/*
**	Return formatted first_name.
*/
std::string Contact::_get_ffirst_name()
{
	if (this->_first_name.length() >= 10)
		return (this->_first_name.substr(0, 9) + ".");
	return (this->_first_name);
}

/*
**	Return formatted last_name.
*/
std::string Contact::_get_flast_name()
{
	if (this->_last_name.length() >= 10)
		return (this->_last_name.substr(0, 9) + ".");
	return (this->_last_name);
}

/*
**	Return formatted nickname.
*/
std::string Contact::_get_fnickname()
{
	if (this->_nickname.length() >= 10)
		return (this->_nickname.substr(0, 9) + ".");
	return (this->_nickname);
}

/*
**	Print brief formatted informations.
*/
void Contact::print_brief_infos(uint8_t i)
{
	std::cout << "|";

	std::cout.width(10);
	std::cout.flags(std::ios::right);
	std::cout
		<< (unsigned int)i
		<< "|";

	std::cout.width(10);
	std::cout.flags(std::ios::right);
	std::cout
		<< this->_get_ffirst_name()
		<< "|";

	std::cout.width(10);
	std::cout.flags(std::ios::right);
	std::cout
		<< this->_get_flast_name()
		<< "|";

	std::cout.width(10);
	std::cout.flags(std::ios::right);
	std::cout
		<< this->_get_fnickname()
		<< "|"
		<< std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

/*
**	Print informations.
*/
void Contact::print_infos(void)
{
	std::cout
		<< "First name: "
		<< this->_first_name
		<< std::endl
		<< "Last name: "
		<< this->_last_name
		<< std::endl
		<< "Nickname: "
		<< this->_nickname
		<< std::endl
		<< "Phone number: "
		<< this->_phone_number
		<< std::endl
		<< "Darkest secret: "
		<< this->_darkest_secret
		<< std::endl;
}
