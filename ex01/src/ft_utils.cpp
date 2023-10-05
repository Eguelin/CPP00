/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:47:18 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/05 15:19:56 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.hpp"

int	ft_check_index( std::string str, int max )
{
	int						index;
	std::string::iterator	it = str.begin();

	while (it != str.end() && std::isspace(*it))
		++it;
	while (it != str.end() && std::isdigit(*it))
		++it;
	while (it != str.end() && std::isspace(*it))
		++it;

	index = std::atoi(str.c_str()) - 1;
	if (index < 0 || index > max || it != str.end())
	{
		std::cerr << "\033[0;31mInvalid index\033[0;0m" << std::endl;
		return (-1);
	}

	return (index);
}

int	ft_check_line( std::string str )
{
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
		if (!std::isprint(*it))
			return (-1);

	return (0);
}

