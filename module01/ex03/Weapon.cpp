/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 23:02:29 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/20 12:49:56 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon ( void ) : type("bare hands") {
}

Weapon::Weapon (const std::string &in_type)
{
	if (in_type.empty())
		this->type = "sweet nothing";
	else
		this->type = in_type;
}

Weapon::~Weapon ( void ) {
}

int	Weapon::setType (const std::string &new_type)
{
	if (new_type.empty())
		this->type = "sweet nothing";
	else
		this->type = new_type;

	return (1);
}

const std::string	&Weapon::getType ( void ) const {
	return (this->type);
}

