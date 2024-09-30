/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:13:54 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/29 20:35:05 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void	FragTrap::frag_init() {
	set_stat(HIT_POINTS, 100);
	set_stat(ENERGY_POINTS, 100);
	set_stat(ATTACK_DAMAGE, 30);
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
	std::cout << name << ": Yaaaay! High five everyone!" << std::endl;
}
