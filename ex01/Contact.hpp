/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:31:58 by agautier          #+#    #+#             */
/*   Updated: 2021/10/30 21:33:05 by agautier         ###   ########.fr       */
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
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

		std::string get_ffirst_name(void);
		std::string get_flast_name(void);
		std::string get_fnickname(void);
};

#endif
