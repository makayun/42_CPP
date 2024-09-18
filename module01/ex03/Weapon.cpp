/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 23:02:29 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/18 08:46:38 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void ) : type("bare hands") {
}

Weapon::Weapon (std::string in_type) : type(in_type) {
}

Weapon::~Weapon ( void ) {
}

int	Weapon::setType (std::string new_type)
{
	this->type = new_type;

	return (1);
}

const std::string	&Weapon::getType ( void ) const {
	return (this->type);
}

