/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 00:50:07 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/29 21:05:08 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <iomanip>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string name;
		void		diamond_init();

	public:
		DiamondTrap( std::string name );
		DiamondTrap( const DiamondTrap &copy);
		DiamondTrap& operator=( const DiamondTrap &copy );
		~DiamondTrap();

		void		attack(const std::string &target);
		void		whoAmI( void );
		std::string	get_name();
};

#endif
