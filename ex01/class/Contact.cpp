/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:05:25 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/29 13:50:49 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Contact::Contact( void )
{
	std::cout << GREEN_T << "Contact constructor called" << DEFAULT_T << std::endl;
}

Contact::~Contact( void )
{
	std::cout << RED_T << "Contact destructor called" << DEFAULT_T << std::endl;
}

/* ************************************************************************** */
/*                              Getters & Setters                             */
/* ************************************************************************** */

const std::string	&Contact::get_first_name( void ) const {return(this->_first_name);}

const std::string	&Contact::get_last_name( void ) const {return(this->_last_name);}

const std::string	&Contact::get_nickname( void ) const {return(this->_nickname);}

const std::string	&Contact::get_phone_number( void ) const {return(this->_phone_number);}

const std::string	&Contact::get_darkest_secret( void ) const {return(this->_darkest_secret);}

void	Contact::set_first_name( const std::string str ) {this->_first_name = str;}

void	Contact::set_last_name( const std::string str ) {this->_last_name = str;}

void	Contact::set_nickname( const std::string str ) {this->_nickname = str;}

void	Contact::set_phone_number( const std::string str ) {this->_phone_number = str;}

void	Contact::set_darkest_secret( const std::string str ) {this->_darkest_secret = str;}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

const std::string	Contact::ft_prompt( int data ) const
{
	const std::string prompt[] = {"First name: ",
								"Last name: ",
								"Nickname: ",
								"Phone number: ",
								"Darkest secret: "};

	if (data < FIRST_NAME || data > DARKEST_SECRET)
	{
		std::cerr << RED_T << "Invalid data" << DEFAULT_T << std::endl;

		return ("");
	}

	return (prompt[data]);
}
