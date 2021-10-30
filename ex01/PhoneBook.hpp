/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:24:00 by agautier          #+#    #+#             */
/*   Updated: 2021/10/31 01:11:28 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "phonebook.h"
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
	
		bool get_cmd(void);

	private:
		uint8_t _index;
		Contact _contacts[8];

		bool _cmd_exit(void) const;
		bool _cmd_add(void);
		bool _cmd_search(void);
		bool _cmd_unknow(void) const;
};

#endif
