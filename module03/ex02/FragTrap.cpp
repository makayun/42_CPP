/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmakagonov <maxmakagonov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:13:54 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/28 00:40:41 by maxmakagono      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void	FragTrap::frag_init() {
	this->set_stat(HIT_POINTS, 100);
	this->set_stat(ENERGY_POINTS, 100);
	this->set_stat(ATTACK_DAMAGE, 30);
	std::cout	<< "ClapTrap known as " << this->get_name() << " is now a beautiful FragTrap" << std::endl;
}

FragTrap::FragTrap() : ClapTrap() {
	this->frag_init();
}

FragTrap::FragTrap( const std::string &in_name ) : ClapTrap(in_name) {
	this->frag_init();
}

FragTrap::FragTrap( const FragTrap &copy ) : ClapTrap(copy) {
	this->name = "graceful but lost creature";
	std::cout	<< "FragTrap known as " << this->get_name() << " is now set but not yet functioning" << std::endl;
	*this = copy;
}

FragTrap& FragTrap::operator=( const FragTrap &copy )
{
    if (this != &copy)
        ClapTrap::operator=(copy);
    return *this;
}

FragTrap::~FragTrap() {
	if (this->get_stat(HIT_POINTS) > 0)
		std::cout << "FragTrap " << this->get_name() << " is now transofrming back to ClapTrap" << std::endl;
}

void FragTrap::attack( const std::string &target ) {
    if (this->get_stat(HIT_POINTS) > 0)
	{
		std::cout	<< this->get_name() << " heals " << target
					<< ", restoring " << this->get_stat(ATTACK_DAMAGE) << " hit points!"
					<< std::endl;
	}
}

