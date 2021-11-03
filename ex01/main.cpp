/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:24:05 by agautier          #+#    #+#             */
/*   Updated: 2021/11/03 16:09:25 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook pb;

	while (pb.get_cmd())
		;
	return (EXIT_SUCCESS);
}
