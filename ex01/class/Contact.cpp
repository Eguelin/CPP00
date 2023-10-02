/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:05:25 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/02 15:55:49 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

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
			std::cout << "\033[0;31mInvalid data\033[0;0m" << std::endl;
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
			std::cout << "\033[0;31mInvalid data\033[0;0m" << std::endl;
			return ;
	}
}

std::string	Contact::ft_prompt(int data) const
{
	switch (data)
	{
		case FIRST_NAME:
			return ("First name : ");
		case LAST_NAME:
			return ("Last name : ");
		case NICKNAME:
			return ("Nickname : ");
		case PHONE_NUMBER:
			return ("Phone number : ");
		case DARKEST_SECRET:
			return ("Darkest secret : ");
		default:
			return ("\033[0;31mInvalid data\033[0;0m");
	}
}
