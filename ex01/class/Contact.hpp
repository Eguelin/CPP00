/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:05:19 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/01 15:17:54 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCONTACT_HPP
#define SCONTACT_HPP

#include <iostream>

class Contact
{
private:

	static int	_nb_contact;
	int			_id;
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;

public:

	Contact(void);
	~Contact(void);

	void	print_contact(void) const;
	void	add_contact(void);
};

#endif
