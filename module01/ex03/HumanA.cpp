/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:39:49 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/19 03:22:05 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

#define HUMAN_A_COLOR "\001\033[36m\002"
#define RESET_COLOR "\001\033[0m\002"

HumanA::HumanA (const std::string &in_name, Weapon &in_weapon)
{
	if (in_name.empty())
		this->name = "Noname";
	else
		this->name = in_name;
	this->weapon = &in_weapon;
}

HumanA::~HumanA ( void ) {
}

int	HumanA::setWeapon(Weapon &new_weapon)
{
	this->weapon = &new_weapon;
	return (1);
}

int HumanA::attack ( void )
{
	std::string out_weapon;

	out_weapon = this->weapon->getType();
	std::cout	<< HUMAN_A_COLOR
				<< this->name
				<< " attacks with their "
				<< out_weapon
				<< RESET_COLOR
				<< std::endl;
	return (1);
}
