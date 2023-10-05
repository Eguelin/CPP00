/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:05:19 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/05 12:43:54 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCONTACT_HPP
#define SCONTACT_HPP

#include <iostream>

typedef enum e_data
{
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	DARKEST_SECRET
}	t_data;

class Contact
{
	private:

		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;

	public:

		Contact( void );
		~Contact( void );

		std::string	getdata( int data ) const;
		void		setdata( int data, std::string str );
		std::string	ft_prompt( int data ) const;
};

#endif
