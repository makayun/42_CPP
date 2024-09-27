/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmakagonov <maxmakagonov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:13:54 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/27 09:05:45 by maxmakagono      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( const std::string &in_name ) : ClapTrap(in_name) {
	stats[HIT_POINTS] = 100;
	stats[ENERGY_POINTS] = 50;
	stats[ATTACK_DAMAGE] = 20;
	std::cout	<< "ClapTrap known as " << name << " is now a beautiful FragTrap" << std::endl;
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
    if (stats[HIT_POINTS] > 0)
	{
		std::cout	<< name << " heals " << target
					<< ", restoring " << stats[ATTACK_DAMAGE] << " hit points!"
					<< std::endl;
	}
}

