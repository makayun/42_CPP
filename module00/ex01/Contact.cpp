/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:32:49 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/16 11:37:17 by mmakagon         ###   ########.fr       */
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

std::string Contact::get_field(int type) const
{
	std::string	ret;

	if (type < 0 || type > 4)
		return (NULL);
	ret = this->field[type];
	return (ret);
}
