/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 01:16:48 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/18 09:06:59 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB (std::string in_name) : name(in_name)
{
	this->weapon = new Weapon();
}

HumanB::~HumanB ( void )
{
	delete this->weapon;
}

int	HumanB::setWeapon(Weapon &new_weapon)
{
	this->weapon = &new_weapon;
	return (1);
}

int HumanB::attack ( void )
{
	std::string out_weapon;

	out_weapon = this->weapon->getType();
	std::cout	<< this->name
				<< " attacks with their "
				<< out_weapon
				<< std::endl;
	return (1);
}
