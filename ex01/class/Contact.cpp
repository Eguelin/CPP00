/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:05:25 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/01 15:24:51 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

static void	print_columns(std::string str);

Contact::Contact(void)
{
	Contact::_nb_contact += 1;
	Contact::_id = Contact::_nb_contact;
}

Contact::~Contact(void)
{
	Contact::_nb_contact -= 1;
}

void	Contact::print_contact(void) const
{
	if (Contact::_id == 1)
		std::cout << "|Index     |First name|Last name |Nickname  |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|" << Contact::_id << "         |";
	print_columns(Contact::_first_name);
	print_columns(Contact::_last_name);
	print_columns(Contact::_nickname);
	std::cout << std::endl;
}

void	Contact::add_contact(void)
{
}

static void	print_columns(std::string str)
{
	std::string	str2 = "          ";

	str2.replace(0, str.length(), str);
	if (str.length() > 10)
		str2.replace(9, str.length(), ".");
	std::cout << str2 << "|";
}

int	Contact::_nb_contact = 0;
