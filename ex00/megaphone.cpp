/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:10:59 by agautier          #+#    #+#             */
/*   Updated: 2021/10/29 15:37:13 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOURD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (EXIT_SUCCESS);
	}
	for (int i = 1; i < argc; i++)
		for (size_t j = 0; j < strlen(argv[i]); j++)
			std::cout << (char)std::toupper(argv[i][j]);
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
