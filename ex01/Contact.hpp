/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:31:58 by agautier          #+#    #+#             */
/*   Updated: 2021/10/31 01:26:18 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "phonebook.h"

class Contact
{
	public:
		Contact(void);
		Contact(std::string info[5]);
		~Contact(void);

		void print_infos(void);
		void print_brief_infos(uint8_t i);
	
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;

		std::string _get_ffirst_name(void);
		std::string _get_flast_name(void);
		std::string _get_fnickname(void);
};

#endif
