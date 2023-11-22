/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:07:28 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/22 14:35:01 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:

		PhoneBook( void );
		~PhoneBook( void );

		void				add( void );
		void				search( void ) const;

	private:

		Contact				_contact[8];
		int					_index;
		int					_nb_index;
		const std::string	&(Contact::*_get[5])( void ) const;
		void				(Contact::*_set[5])( const std::string str );
};

#endif
