/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:05:08 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/25 19:23:30 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

PhoneBook::PhoneBook( void ): _index(0), _nb_index(0)
{
	std::cout << GREEN_T << "PhoneBook constructor called" << RESET_T << std::endl;

	this->_get[FIRST_NAME] = &Contact::get_first_name;
	this->_get[LAST_NAME] = &Contact::get_last_name;
	this->_get[NICKNAME] = &Contact::get_nickname;
	this->_get[PHONE_NUMBER] = &Contact::get_phone_number;
	this->_get[DARKEST_SECRET] = &Contact::get_darkest_secret;

	this->_set[FIRST_NAME] = &Contact::set_first_name;
	this->_set[LAST_NAME] = &Contact::set_last_name;
	this->_set[NICKNAME] = &Contact::set_nickname;
	this->_set[PHONE_NUMBER] = &Contact::set_phone_number;
	this->_set[DARKEST_SECRET] = &Contact::set_darkest_secret;
}

PhoneBook::~PhoneBook( void )
{
	std::cout << RED_T << "PhoneBook destructor called" << RESET_T << std::endl;
}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

void	PhoneBook::add( void )
{
	std::string				line;
	std::string::iterator	it;

	for (int i = FIRST_NAME; i <= DARKEST_SECRET; i++)
	{
		std::cout << YELLOW_T << this->_contact[this->_index].ft_prompt(i) << RESET_T;
		std::getline(std::cin, line);

		if (std::cin.eof())
			return ;

		it = line.begin();
		while (it != line.end() && std::isprint(*it))
			++it;

		if (line.empty() || it != line.end())
		{
			std::cerr << RED_T << "Invalid input" << RESET_T << std::endl;

			i--;

			continue ;
		}

		(this->_contact[this->_index].*_set[i])(line);
	}

	this->_index++;

	if (this->_nb_index < 8)
		this->_nb_index++;

	if (this->_index == 8)
		this->_index = 0;
}

void	PhoneBook::search( void ) const
{
	int					index;

	std::cout << BLUE_T;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;

	for (int i = 0; i < this->_nb_index; i++)
	{
		std::cout << "|         " << (i + 1) << "|";

		for (int j = FIRST_NAME; j <= NICKNAME; j++)
		{
			if ((this->_contact[i].*_get[j])().length() > 10)
				std::cout << (this->_contact[i].*_get[j])().substr(0, 9) << ".|";
			else
				std::cout << std::setw(10) << (this->_contact[i].*_get[j])() << "|";
		}

		std::cout << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
	}

	std::cout << RESET_T;

	if (!this->_nb_index)
		return ;

	while (1)
	{
		std::cout << YELLOW_T << "Enter the desired index : " << RESET_T;
		std::cin >> index;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (std::cin.eof())
			return ;

		if (index < 1 || index > this->_nb_index)
			std::cerr << RED_T << "Invalid index" << RESET_T << std::endl;
		else
		{
			index--;

			std::cout << BLUE_T;

			for (int i = FIRST_NAME; i <= DARKEST_SECRET; i++)
				std::cout << this->_contact[index].ft_prompt(i) << (this->_contact[index].*_get[i])() << std::endl;

			std::cout << RESET_T;

			return ;
		}
	}
}
