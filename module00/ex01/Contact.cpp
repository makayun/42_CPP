/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:32:49 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/13 13:48:13 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

int Contact::set_field(int type, std::string in_field)
{
	if (type < 0 || type > 4 || in_field.empty())
		return (ERROR);
	this->field[type] = in_field;
	return (ALL_FINE);
}

std::string Contact::get_field(int type)
{
	std::string	ret;
	
	if (type < 0 || type > 4)
		return (NULL);
	ret = this->field[type];
	return (ret);
}

size_t Contact::get_max_fields(void)
{
	return (this->field.size());
}
