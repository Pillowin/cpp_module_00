/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:10:59 by agautier          #+#    #+#             */
/*   Updated: 2021/11/11 10:51:54 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdint.h>

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (EXIT_SUCCESS);
	}
	for (uint8_t i = 1; i < argc; i++)
		for (size_t j = 0; j < strlen(argv[i]); j++)
			std::cout << (char)std::toupper(argv[i][j]);
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
