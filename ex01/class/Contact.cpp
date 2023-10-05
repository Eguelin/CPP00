/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:05:25 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/05 15:20:50 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void )
{
}

Contact::~Contact( void )
{
}

std::string	Contact::getdata( int data ) const
{
	std::string	const str_data[] = {Contact::_first_name, Contact::_last_name, Contact::_nickname, \
						Contact::_phone_number, Contact::_darkest_secret};

	if (data < FIRST_NAME || data > DARKEST_SECRET)
	{
		std::cerr << "\033[0;31mInvalid data\033[0;0m" << std::endl;
		return ("");
	}

	return (str_data[data]);
}

void	Contact::setdata( int data, std::string str )
{
	std::string	*str_data[] = {&this->_first_name, &this->_last_name, &this->_nickname, \
						&this->_phone_number, &this->_darkest_secret};

	if (data < FIRST_NAME || data > DARKEST_SECRET)
		std::cerr << "\033[0;31mInvalid data\033[0;0m" << std::endl;

	*str_data[data] = str;
}

std::string	Contact::ft_prompt( int data ) const
{
	std::string	const prompt[] = {"First name : ", "Last name : ", "Nickname : ", \
							"Phone number : ", "Darkest secret : "};

	if (data < FIRST_NAME || data > DARKEST_SECRET)
	{
		std::cerr << "\033[0;31mInvalid data\033[0;0m" << std::endl;
		return ("");
	}

	return (prompt[data]);
}
