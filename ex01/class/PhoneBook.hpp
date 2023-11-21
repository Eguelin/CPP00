/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:07:28 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/21 23:29:57 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:

		Contact				_contact[8];
		int					_index;
		int					_nb_index;
		const std::string	&(Contact::*get[5])( void ) const;
		void				(Contact::*set[5])( const std::string str );

	public:

		PhoneBook( void );
		~PhoneBook( void );

		void				add( void );
		void				search( void ) const;
};

#endif
