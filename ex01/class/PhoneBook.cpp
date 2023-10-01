/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:05:08 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/01 18:33:09 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

static void	ft_print_columns(std::string const str);

PhoneBook::PhoneBook(void)
{
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::add(void)
{
	static int	i;

	PhoneBook::contact[i].setcontact();
	i++;
	if (i == 8)
		i = 0;
}

void	PhoneBook::search(void) const
{
	std::cout << "|Index     |First name|Last name |Nickname  |" << std::endl;
	for (size_t i = 0; i < 8; i++)
	{
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		std::cout << "|" << (i + 1) << "         |";
		ft_print_columns(PhoneBook::contact[i].getdata(FIRST_NAME));
		ft_print_columns(PhoneBook::contact[i].getdata(LAST_NAME));
		ft_print_columns(PhoneBook::contact[i].getdata(NICKNAME));
		std::cout << std::endl;
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

static void	ft_print_columns(std::string const str)
{
	std::string	str2 = "          ";

	str2.replace(0, str.length(), str);
	if (str.length() > 10)
		str2.replace(9, str.length(), ".");
	std::cout << str2 << "|";
}

void	PhoneBook::search(int	i) const
{
	if (i < 0 || i > 7)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	PhoneBook::contact[i - 1].print_contact();
}
