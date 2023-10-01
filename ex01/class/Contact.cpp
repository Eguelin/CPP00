/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:05:25 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/01 18:15:07 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

static void	ft_print_prompt(int data);

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string	Contact::getdata(int data) const
{
	switch (data) {
		case FIRST_NAME:
			return (Contact::_first_name);
		case LAST_NAME:
			return (Contact::_last_name);
		case NICKNAME:
			return (Contact::_nickname);
		case PHONE_NUMBER:
			return (Contact::_phone_number);
		case DARKEST_SECRET:
			return (Contact::_darkest_secret);
		default:
			std::cout << "Invalid data" << std::endl;
			return ("");
	}
}

void	Contact::setdata(int data, std::string str)
{
	switch (data)
	{
		case FIRST_NAME:
			Contact::_first_name = str;
			return ;
		case LAST_NAME:
			Contact::_last_name = str;
			return ;
		case NICKNAME:
			Contact::_nickname = str;
			return ;
		case PHONE_NUMBER:
			Contact::_phone_number = str;
			return ;
		case DARKEST_SECRET:
			Contact::_darkest_secret = str;
			return ;
		default:
			std::cout << "Invalid data" << std::endl;
			return ;
	}
}

void	Contact::setcontact(void)
{
	std::string	str;

	for (size_t i = FIRST_NAME; i <= DARKEST_SECRET; i++)
	{
		ft_print_prompt(i);
		std::cin >> str;
		setdata(i, str);
	}
}

void	Contact::print_contact(void) const
{
	for (size_t i = FIRST_NAME; i <= DARKEST_SECRET; i++)
	{
		ft_print_prompt(i);
		std::cout << getdata(i) << std::endl;
	}
}

static void	ft_print_prompt(int data)
{
	switch (data)
	{
		case FIRST_NAME:
			std::cout << "First name : ";
			return ;
		case LAST_NAME:
			std::cout << "Last name : ";
			return ;
		case NICKNAME:
			std::cout << "Nickname : ";
			return ;
		case PHONE_NUMBER:
			std::cout << "Phone number : ";;
			return ;
		case DARKEST_SECRET:
			std::cout << "Darkest secret : ";
			return ;
		default:
			std::cout << "Invalid data" << std::endl;
			return ;
	}
}
