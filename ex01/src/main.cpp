/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:39:04 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/05 12:56:17 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main( void )
{
	PhoneBook	PhoneBook;
	std::string	line;

	while (line != "EXIT")
	{
		std::getline(std::cin, line);
		if (std::cin.eof())
		{
			std::cout << "EXIT" << std::endl;
			return (0);
		}
		else if (line == "ADD")
			PhoneBook.add();
		else if (line == "SEARCH")
			PhoneBook.search();
	}
	return (0);
}
