/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:05:19 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/21 23:55:22 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCONTACT_HPP
# define SCONTACT_HPP

# include "text_color.hpp"
# include <iostream>

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

		const std::string	&get_first_name( void ) const;
		const std::string	&get_last_name( void ) const;
		const std::string	&get_nickname( void ) const;
		const std::string	&get_phone_number( void ) const;
		const std::string	&get_darkest_secret( void ) const;

		void				set_first_name( const std::string str );
		void				set_last_name( const std::string str );
		void				set_nickname( const std::string str );
		void				set_phone_number( const std::string str );
		void				set_darkest_secret( const std::string str );

		const std::string	ft_prompt( int data ) const;
};

#endif
