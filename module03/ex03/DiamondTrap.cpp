/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 01:03:27 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/29 21:24:14 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void	DiamondTrap::diamond_init() {
	FragTrap::init_hp();
	ScavTrap::init_ep();
	FragTrap::init_ad();
	std::cout << "DiamondTrap known as " << name << " is here now, just take it" << std::endl;
}

DiamondTrap::DiamondTrap(std::string in_name) : ClapTrap(in_name + "_clap_name") {
	std::string temp;

	if (in_name.empty())
		temp = "Noname";
	else
		temp = in_name;
	name = set_color(temp) + temp + COLOR_RES;
	diamond_init();
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy) {
	this->name = "a funky creature";
	std::cout	<< "DiamondTrap known as " << this->name << " is observing you" << std::endl;
	*this = copy;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap &copy )
{
	if (this != &copy)
		ClapTrap::operator=(copy);
	this->name = copy.name;
	this->name.insert(this->name.find(COLOR_RES), "_copy");
	return *this;
}

DiamondTrap::~DiamondTrap() {
	if (stats[HIT_POINTS] > 0)
		std::cout << "DiamondTrap " << name << " had stopped observing you" << std::endl;
}

void	DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

std::string	DiamondTrap::get_name() {
	return (this->name);
}

void	DiamondTrap::whoAmI() {
	std::cout << "\nSay my name, you know who I am!\n";
	std::cout << std::left << std::setw(25) << "Diamond name" << name << std::endl;
	std::cout << std::setw(25) << "Clap name" << ClapTrap::name << std::endl;
	std::cout << std::setw(25) << "Hit points" << stats[HIT_POINTS] << std::endl;
	std::cout << std::setw(25) << "Energy points" << stats[ENERGY_POINTS] << std::endl;
	std::cout << std::setw(25) << "Attack damage" << stats[ATTACK_DAMAGE] << "\n" << std::endl;
}
