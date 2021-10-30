/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:24:05 by agautier          #+#    #+#             */
/*   Updated: 2021/10/30 22:50:16 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"
#include "PhoneBook.hpp"

// TODO: index should overflow
int main(void)
{
	PhoneBook pb;

	while (pb.get_cmd())
		;
	return (EXIT_SUCCESS);
}
