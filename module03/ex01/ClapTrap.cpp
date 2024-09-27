/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmakagonov <maxmakagonov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:03:09 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/26 14:08:29 by maxmakagono      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

std::string	ClapTrap::set_color( const std::string &in_name )
{
	const std::string	colors[5] = {
		"\033[31m", // Red
		"\033[34m", // Blue
		"\033[35m", // Magenta
		"\033[32m", // Green
		"\033[33m", // Yellow
	};
	int					index;

	index = in_name[0] % 5;

	return (colors[index]);
}

ClapTrap::ClapTrap( const std::string &in_name ) : is_destroyed(false) {
	std::string	temp;
	std::string	color;	

	if (in_name.empty())
		temp = "Noname";
	else
		temp = in_name;
	color = set_color( temp );
	
	this->name = color + temp + COLOR_RES;
	stats[HIT_POINTS] = 10;
	stats[ENERGY_POINTS] = 10;
	stats[ATTACK_DAMAGE] = 10;
	std::cout	<< "ClapTrap known as " << name << " is now set and functioning" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &copy ) {
	this->name = "an empty junk";
	std::cout	<< "ClapTrap known as " << name << " is now set but not yet functioning" << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator= ( const ClapTrap &copy ) {
	std::cout << this->name << " is now a copy of " << copy.get_name() << std::endl;
	for (size_t i = 0; i < STATS_MAX; i++)
		stats[i] = copy.get_stat( i );
	if (stats[HIT_POINTS] <= 0)
		this->is_destroyed = true; 
	this->name = copy.get_name();
	this->name.insert( this->name.find(COLOR_RES), "_copy" );
	return (*this);
}

ClapTrap::~ClapTrap() {
	if (this->is_destroyed == false)
		std::cout << "ClapTrap " << name << " is now turned off." << std::endl;
}

void	ClapTrap::set_stat( size_t stat_id, long const &in_value ) {
	if (stat_id < STATS_MAX)
		this->stats[stat_id] = in_value;
}

long	ClapTrap::get_stat( size_t stat_id ) const {
	if (stat_id < STATS_MAX)
		return (this->stats[stat_id]);
	else
		return (LONG_MIN);
}

void	ClapTrap::attack( const std::string& target ) {
	if (this->is_destroyed == false)
	{
		std::cout	<< name << " attacks " << target
					<< " causing " << stats[ATTACK_DAMAGE] << " points of damage!"
					<< std::endl;
	}
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (this->is_destroyed == false)
	{
		const long signed_amount = static_cast<long>(amount);
	
		stats[HIT_POINTS] -= signed_amount;
		std::cout << name << " takes " << amount << " damage" << std::endl;
		
		if (stats[HIT_POINTS] > 0)
			print_hp();
		else
		{
			this->is_destroyed = true;
			std::cout << name << " is now destroyed" << std::endl;
		}
	}
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (this->is_destroyed == false)
	{
		const long signed_amount = static_cast<long>(amount);
	
		stats[HIT_POINTS] += signed_amount;
		if (stats[HIT_POINTS] < 0)
			stats[HIT_POINTS] = LONG_MAX;
		std::cout << name << " has repaired " << amount << " hit points" << std::endl;
		print_hp();
	}
}

const std::string& ClapTrap::get_name(void) const {
    return name;
}


void ClapTrap::print_hp( void ) {
	std::cout << name << "'s current HP is " << stats[HIT_POINTS] << std::endl;
}
