/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:39:04 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/23 18:34:53 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main( void )
{
	PhoneBook	PhoneBook;
	std::string	line;

	std::cout << std::endl;
	std::cout << BGREEN_T << "Welcome to PhoneBook" << std::endl;
	std::cout << "ADD : Enables a new contact to be registeRED_T." << std::endl;
	std::cout << "SEARCH: Displays the list of saved contacts." << std::endl;
	std::cout << "EXIT: Exits the program." << RESET_T << std::endl;

	while (line != "EXIT")
	{
		std::getline(std::cin, line);
		if (std::cin.eof())
		{
			std::cout << "EXIT" << std::endl << std::endl;
			return (0);
		}
		else if (line == "ADD")
			PhoneBook.add();
		else if (line == "SEARCH")
			PhoneBook.search();
	}

	std::cout << std::endl;

	return (0);
}
