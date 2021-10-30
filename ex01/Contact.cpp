/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:32:55 by agautier          #+#    #+#             */
/*   Updated: 2021/10/30 22:23:01 by agautier         ###   ########.fr       */
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
Contact::Contact(std::string info[5]) :	first_name(info[0]),
										last_name(info[1]),
										nickname(info[2]),
										phone_number(info[3]),
										darkest_secret(info[4])
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
std::string Contact::get_ffirst_name()
{
	if (this->first_name.length() >= 10)
		return (this->first_name.substr(0, 9) + ".");
	return (this->first_name);
}

/*
**	Return formatted last_name.
*/
std::string Contact::get_flast_name()
{
	if (this->last_name.length() >= 10)
		return (this->last_name.substr(0, 9) + ".");
	return (this->last_name);
}

/*
**	Return formatted nickname.
*/
std::string Contact::get_fnickname()
{
	if (this->nickname.length() >= 10)
		return (this->nickname.substr(0, 9) + ".");
	return (this->nickname);
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
		<< this->get_ffirst_name()
		<< "|";

	std::cout.width(10);
	std::cout.flags(std::ios::right);
	std::cout
		<< this->get_flast_name()
		<< "|";

	std::cout.width(10);
	std::cout.flags(std::ios::right);
	std::cout
		<< this->get_fnickname()
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
		<< this->first_name
		<< std::endl
		<< "Last name: "
		<< this->last_name
		<< std::endl
		<< "Nickname: "
		<< this->nickname
		<< std::endl
		<< "Phone number: "
		<< this->phone_number
		<< std::endl
		<< "Darkest secret: "
		<< this->darkest_secret
		<< std::endl;
}
