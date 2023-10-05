/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:05:08 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/05 15:27:27 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.hpp"
#include <cstdlib>

static void	ft_print_columns( std::string const str );

PhoneBook::PhoneBook( void )
{
	PhoneBook::_index = 0;
}

PhoneBook::~PhoneBook( void )
{
}

void	PhoneBook::add( void )
{
	static int	i = 0;
	int 		j = FIRST_NAME;
	std::string	line;

	while (j <= DARKEST_SECRET || line == "")
	{
		line = "";
		std::cout << PhoneBook::_contact[i].ft_prompt(j);
		std::getline(std::cin, line);
		if (std::cin.eof())
			return ;
		else if (line == "" || ft_check_line(line))
			std::cerr << "\033[0;31mInvalid input\033[0;0m" << std::endl;
		else
			PhoneBook::_contact[i].setdata(j++, line);
	}

	i++;

	if (PhoneBook::_index < i)
		PhoneBook::_index++;

	if (i == 8)
		i = 0;
}

void	PhoneBook::search( void ) const
{
	int			index = -1;
	std::string	line;

	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;

	for (int i = 0; i < PhoneBook::_index; i++)
	{
		std::cout << "|         " << (i + 1) << "|";
		ft_print_columns(PhoneBook::_contact[i].getdata(FIRST_NAME));
		ft_print_columns(PhoneBook::_contact[i].getdata(LAST_NAME));
		ft_print_columns(PhoneBook::_contact[i].getdata(NICKNAME));
		std::cout << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
	}

	if (!PhoneBook::_index)
		return ;

	while (index == -1)
	{
		std::cout << "Enter the desired index : ";
		std::getline(std::cin, line);
		if (std::cin.eof())
			return ;
		index = ft_check_index(line, PhoneBook::_index - 1);
	}

	for (int j = FIRST_NAME; j <= DARKEST_SECRET; j++)
		std::cout << PhoneBook::_contact[index].ft_prompt(j) << PhoneBook::_contact[index].getdata(j) << std::endl;
}

static void	ft_print_columns( std::string const str )
{
	std::string	str2 = "          ";

	if (str.length() > 10)
	{
		str2.replace(0, str.length(), str);
		str2.replace(9, str.length(), ".");
	}
	else
		str2.replace(10 - str.length(), str.length(), str);

	std::cout << str2 << "|";
}
