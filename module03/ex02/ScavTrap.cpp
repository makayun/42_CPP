/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmakagonov <maxmakagonov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:13:54 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/27 09:05:05 by maxmakagono      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap( const std::string &in_name ) : ClapTrap(in_name), gate_keeper_mode(false) {
	stats[HIT_POINTS] = 100;
	stats[ENERGY_POINTS] = 50;
	stats[ATTACK_DAMAGE] = 20;
	std::cout	<< "ClapTrap known as " << name << " is transformed to ScavTrap" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &copy ) : ClapTrap(copy) {
	this->name = "an empty junk";
	std::cout	<< "ScavTrap known as " << name << " is now set but not yet functioning" << std::endl;
	*this = copy;
}

ScavTrap& ScavTrap::operator=( const ScavTrap &copy)
{
    if (this != &copy)
        ClapTrap::operator=(copy);
	this->gate_keeper_mode = copy.gate_keeper_mode;
    return *this;
}

ScavTrap::~ScavTrap() {
	if (stats[HIT_POINTS] > 0)
		std::cout << "ScavTrap " << name << " is now transofrming back to ClapTrap" << std::endl;
}

void ScavTrap::attack( const std::string &target ) {
    if (stats[HIT_POINTS] > 0)
	{
		std::cout	<< name << " coldly attacks " << target
					<< ", heartlessly causing " << stats[ATTACK_DAMAGE] << " points of damage!"
					<< std::endl;
	}
}

void ScavTrap::guardGate() {
	if (stats[HIT_POINTS] > 0)
    {
		gate_keeper_mode = true;
		std::cout << name << " now guards the gate" << std::endl;
	}
}
