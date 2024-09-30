/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:13:54 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/29 21:22:50 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void	FragTrap::init_hp() {
	this->stats[HIT_POINTS] = 100;
}

void	FragTrap::init_ep() {
	this->stats[ENERGY_POINTS] = 100;
}

void	FragTrap::init_ad() {
	this->stats[ATTACK_DAMAGE] = 30;
}

void	FragTrap::frag_init()
{
	init_hp();
	init_ep();
	init_ad();
	std::cout << "ClapTrap known as " << name << " is now a beautiful FragTrap" << std::endl;
}

FragTrap::FragTrap() : ClapTrap() {
	frag_init();
}

FragTrap::FragTrap( const std::string &in_name ) : ClapTrap(in_name) {
	frag_init();
}

FragTrap::FragTrap( const FragTrap &copy ) : ClapTrap(copy) {
	this->name = "graceful but lost creature";
	std::cout	<< "FragTrap known as " << name << " is now set but not yet functioning" << std::endl;
	*this = copy;
}

FragTrap& FragTrap::operator=( const FragTrap &copy )
{
	if (this != &copy)
		ClapTrap::operator=(copy);
	return *this;
}

FragTrap::~FragTrap() {
	if (stats[HIT_POINTS] > 0)
		std::cout << "FragTrap " << name << " is now transofrming back to ClapTrap" << std::endl;
}

void FragTrap::attack( const std::string &target ) {
	if (stats[ENERGY_POINTS] <= 0)
		std::cout << "Not enough energy points!" << std::endl;
	else if (stats[HIT_POINTS] > 0)
	{
		--stats[ENERGY_POINTS];
		std::cout	<< name << " heals " << target
					<< ", restoring " << stats[ATTACK_DAMAGE] << " hit points!"
					<< std::endl;
	}
}

void	FragTrap::highFivesGuys() {
	std::cout << name << ": Yaaaay! High five everyone!\n" << std::endl;
}
