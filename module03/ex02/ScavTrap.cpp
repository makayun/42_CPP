/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:13:54 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/29 20:12:12 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	ScavTrap::scav_init()
{
	this->set_stat(HIT_POINTS, 100);
	this->set_stat(ENERGY_POINTS, 50);
	this->set_stat(ATTACK_DAMAGE, 20);
	std::cout	<< "ClapTrap known as " << name << " is transformed to ScavTrap" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap(), gate_keeper_mode(false) {
	this->scav_init();
}

ScavTrap::ScavTrap( const std::string &in_name ) : ClapTrap(in_name), gate_keeper_mode(false) {
	this->scav_init();
}

ScavTrap::ScavTrap( const ScavTrap &copy ) : ClapTrap(copy) {
	this->name = "an empty junk";
	std::cout	<< "ScavTrap known as " << this->get_name() << " is now set but not yet functioning" << std::endl;
	*this = copy;
}

ScavTrap& ScavTrap::operator=( const ScavTrap &copy ) {
	if (this != &copy)
		ClapTrap::operator=(copy);
	return *this;
}

ScavTrap::~ScavTrap() {
	if (this->get_stat(HIT_POINTS) > 0)
		std::cout << "ScavTrap " << this->get_name() << " is now transofrming back to ClapTrap" << std::endl;
}

void ScavTrap::attack( const std::string &target ) {
	if (stats[ENERGY_POINTS] <= 0)
		std::cout << "Not enough energy points!" << std::endl;
	else if (this->get_stat(HIT_POINTS) > 0)
	{
		--stats[ENERGY_POINTS];
		std::cout	<< this->get_name() << " coldly attacks " << target
					<< ", heartlessly causing " << this->get_stat(ATTACK_DAMAGE) << " points of damage!"
					<< std::endl;
	}
}

void ScavTrap::guardGate() {
	gate_keeper_mode = true;
	std::cout << this->get_name() << " now guards the gate" << std::endl;
}
