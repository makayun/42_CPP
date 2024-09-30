/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:03:09 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/29 20:33:02 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

std::string	ClapTrap::set_color( const std::string &in_name )
{
	int					index;
	const std::string	colors[5] = {
		"\033[32m", // Green
		"\033[34m", // Blue
		"\033[35m", // Magenta
		"\033[31m", // Red
		"\033[33m", // Yellow
	};

	index = in_name[0] % 5;

	return (colors[index]);
}

void	ClapTrap::clap_init() {
	set_stat(HIT_POINTS, 10);
	set_stat(ENERGY_POINTS, 10);
	set_stat(ATTACK_DAMAGE, 10);
	std::cout	<< "ClapTrap known as " << name << " is now set and functioning" << std::endl;
}

ClapTrap::ClapTrap() {
	set_name("DEFAULT");
	clap_init();
}

ClapTrap::ClapTrap( const std::string &in_name ) {
	std::string	temp;
	std::string	color;

	if (in_name.empty())
		temp = "Noname";
	else if (in_name == "_clap_name")
		temp = "Noname" + in_name;
	else
		temp = in_name;
	color = set_color( temp );
	name = color + temp + COLOR_RES;
	clap_init();
}

ClapTrap::ClapTrap( const ClapTrap &copy ) {
	name = "an empty junk";
	std::cout	<< "ClapTrap known as " << name << " is now set but not yet functioning" << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator= ( const ClapTrap &copy ) {
	std::cout << this->name << " is now a copy of " << copy.get_name() << std::endl;
	for (size_t i = 0; i < STATS_MAX; i++)
		this->stats[i] = copy.get_stat(i);
	this->name = copy.get_name();
	this->name.insert( this->name.find(COLOR_RES), "_copy" );
	return (*this);
}

ClapTrap::~ClapTrap() {
	if (get_stat(HIT_POINTS) > 0)
		std::cout << get_name() << " is now turned off." << std::endl;
}

void	ClapTrap::set_stat( size_t stat_id, long const &in_value ) {
	if (stat_id < STATS_MAX)
		stats[stat_id] = in_value;
}

long	ClapTrap::get_stat( size_t stat_id ) const {
	if (stat_id < STATS_MAX)
		return (stats[stat_id]);
	else
		return (LONG_MIN);
}

void	ClapTrap::attack( const std::string& target ) {
	if (stats[HIT_POINTS] > 0)
	{
		if (stats[ENERGY_POINTS] <= 0) {
			std::cout << "Not enough energy points!" << std::endl;
			return ;
		}
		--stats[ENERGY_POINTS];
		std::cout	<< name << " attacks " << target
					<< " causing " << stats[ATTACK_DAMAGE] << " points of damage!"
					<< std::endl;
		print_ep();
	}
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (stats[HIT_POINTS] > 0 && amount > 0)
	{
		const long signed_amount = static_cast<long>(amount);

		stats[HIT_POINTS] -= signed_amount;
		std::cout << name << " takes " << amount << " damage" << std::endl;

		if (stats[HIT_POINTS] > 0)
			print_hp();
		else
		{
			std::cout << name << " is now destroyed" << std::endl;
			stats[ATTACK_DAMAGE] = 0;
		}
	}
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (stats[HIT_POINTS] > 0)
	{
		if (stats[ENERGY_POINTS] <= 0) {
			std::cout << "Not enough energy points!" << std::endl;
			return ;
		}
		const long signed_amount = static_cast<long>(amount);

		stats[HIT_POINTS] += signed_amount;
		if (stats[HIT_POINTS] < 0)
			stats[HIT_POINTS] = LONG_MAX;
		--stats[ENERGY_POINTS];
		std::cout << name << " has repaired " << amount << " hit points" << std::endl;
		print_hp();
		print_ep();
	}
}

const std::string& ClapTrap::get_name(void) const {
	return (this->name);
}

void	ClapTrap::set_name( const std::string &in_name ) {
	this->name = in_name;
}

void ClapTrap::print_ep( void ) {
	std::cout << name << "'s current EP is " << stats[ENERGY_POINTS] << std::endl;
}


void ClapTrap::print_hp( void ) {
	std::cout << name << "'s current HP is " << stats[HIT_POINTS] << std::endl;
}
