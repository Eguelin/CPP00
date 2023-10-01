/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:05:08 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/01 19:36:06 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <cstdlib>

static void	ft_print_columns(std::string const str);

PhoneBook::PhoneBook(void)
{
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::add(void)
{
	static int	i = 0;

	PhoneBook::_contact[i].setcontact();
	i++;
	if (PhoneBook::_index < i)
		PhoneBook::_index += 1;
	if (i == 8)
		i = 0;
}

void	PhoneBook::search(void) const
{
	std::string		index;

	std::cout << "|Index     |First name|Last name |Nickname  |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|" << (i + 1) << "         |";
		ft_print_columns(PhoneBook::_contact[i].getdata(FIRST_NAME));
		ft_print_columns(PhoneBook::_contact[i].getdata(LAST_NAME));
		ft_print_columns(PhoneBook::_contact[i].getdata(NICKNAME));
		std::cout << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
	}
	std::cout << "Enter the desired index : ";
	std::getline(std::cin, index);
	if (std::atoi(index.c_str()) < 1 || std::atoi(index.c_str()) > 8)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	PhoneBook::_contact[std::atoi(index.c_str()) - 1].print_contact();
}

static void	ft_print_columns(std::string const str)
{
	std::string	str2 = "          ";

	str2.replace(0, str.length(), str);
	if (str.length() > 10)
		str2.replace(9, str.length(), ".");
	std::cout << str2 << "|";
}



