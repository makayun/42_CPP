/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 01:16:48 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/19 02:38:44 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#define HUMAN_B_COLOR "\001\033[35m\002"
#define RESET_COLOR "\001\033[0m\002"

static Weapon empty;

HumanB::HumanB (const std::string &in_name)
{
	if (in_name.empty())
		this->name = "Noname";
	else
		this->name = in_name;
	this->weapon = &empty;
}

HumanB::HumanB (const std::string &in_name, Weapon &in_weapon)
{
	if (in_name.empty())
		this->name = "Noname";
	else
		this->name = in_name;
	this->weapon = &in_weapon;
}

HumanB::~HumanB ( void ) {
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
	std::cout	<< HUMAN_B_COLOR
				<< this->name
				<< " attacks with their "
				<< out_weapon
				<< RESET_COLOR
				<< std::endl;
	return (1);
}
