/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:39:04 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/01 15:05:58 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "My_Awesome_PhoneBook.hpp"

int main(void)
{
	PhoneBook test;

	test.contact[0].print_contact();
	test.contact[1].print_contact();
	test.contact[2].print_contact();
	test.contact[3].print_contact();
	test.contact[4].print_contact();
	test.contact[5].print_contact();
	test.contact[6].print_contact();
	test.contact[7].print_contact();
	return 0;
}
