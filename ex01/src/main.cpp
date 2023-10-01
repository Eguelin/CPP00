/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:39:04 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/01 18:31:54 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "My_Awesome_PhoneBook.hpp"

int main(void)
{
	PhoneBook	PhoneBook;
	std::string	str;

	while (str != "EXIT")
	{
		std::cin >> str;
		if (str == "ADD")
			PhoneBook.add();
		else if (str == "SEARCH")
			PhoneBook.search();
	}
	return (0);
}
