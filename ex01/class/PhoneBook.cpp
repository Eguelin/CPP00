/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:05:08 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/22 00:18:50 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>

static int	ft_check_index( const std::string str, int max );
static void	ft_print_columns( const std::string str );
static bool	ft_check_line( const std::string str );

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

PhoneBook::PhoneBook( void ): _index(0), _nb_index(0)
{
	std::cout << BLACK << "PhoneBook constructor called" << RESET_TEXT << std::endl;

	get[FIRST_NAME] = &Contact::get_first_name;
	get[LAST_NAME] = &Contact::get_last_name;
	get[NICKNAME] = &Contact::get_nickname;
	get[PHONE_NUMBER] = &Contact::get_phone_number;
	get[DARKEST_SECRET] = &Contact::get_darkest_secret;

	set[FIRST_NAME] = &Contact::set_first_name;
	set[LAST_NAME] = &Contact::set_last_name;
	set[NICKNAME] = &Contact::set_nickname;
	set[PHONE_NUMBER] = &Contact::set_phone_number;
	set[DARKEST_SECRET] = &Contact::set_darkest_secret;

	return ;
}

PhoneBook::~PhoneBook( void )
{
	std::cout << BLACK << "PhoneBook destructor called" << RESET_TEXT << std::endl;

	return ;
}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

void	PhoneBook::add( void )
{
	int 		i = FIRST_NAME;
	std::string	line = "";

	while (i <= DARKEST_SECRET && line == "")
	{
		std::cout << this->_contact[this->_index].ft_prompt(i);
		std::getline(std::cin, line);

		if (std::cin.eof())
			return ;
		else if (ft_check_line(line) == false)
			std::cerr << RED << "Invalid input" << RESET_TEXT << std::endl;
		else
		{
			(this->_contact[this->_index].*set[i])(line);
			i++;
		}

		line = "";
	}

	this->_index++;

	if (this->_nb_index < 8)
		this->_nb_index++;

	if (this->_index == 8)
		this->_index = 0;
}

void	PhoneBook::search( void ) const
{
	int					index = -1;
	std::string			line;

	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;

	for (int i = 0; i < this->_nb_index; i++)
	{
		std::cout << "|         " << (i + 1) << "|";

		for (int j = FIRST_NAME; j <= NICKNAME; j++)
			ft_print_columns((this->_contact[i].*get[j])());

		std::cout << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
	}

	if (!this->_nb_index)
		return ;

	while (index == -1)
	{
		std::cout << "Enter the desired index : ";
		std::getline(std::cin, line);

		if (std::cin.eof())
			return ;

		index = ft_check_index(line, this->_nb_index - 1);
	}

	for (int i = FIRST_NAME; i <= DARKEST_SECRET; i++)
		std::cout << this->_contact[index].ft_prompt(i) << (this->_contact[index].*get[i])() << std::endl;
}

/* ************************************************************************** */
/*                              Static functions                              */
/* ************************************************************************** */


static int	ft_check_index( const std::string str, int max )
{
	int							index;
	std::string::const_iterator	it = str.begin();

	while (it != str.end() && std::isspace(*it))
		++it;
	while (it != str.end() && std::isdigit(*it))
		++it;
	while (it != str.end() && std::isspace(*it))
		++it;

	index = std::atoi(str.c_str()) - 1;
	if (index < 0 || index > max || it != str.end())
	{
		std::cerr << RED << "Invalid index" << RESET_TEXT << std::endl;

		return (-1);
	}

	return (index);
}

static void	ft_print_columns( const std::string str )
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

static bool	ft_check_line( const std::string str )
{
	if (str == "")
		return (false);

	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
		if (!std::isprint(*it))
			return (false);

	return (true);
}
