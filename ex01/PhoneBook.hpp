/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:24:00 by agautier          #+#    #+#             */
/*   Updated: 2021/10/30 22:49:49 by agautier         ###   ########.fr       */
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
		uint8_t index;
		Contact contacts[8];

		bool cmd_exit(void) const;
		bool cmd_add(void);
		bool cmd_search(void);
		bool cmd_unknow(void) const;
};

#endif
