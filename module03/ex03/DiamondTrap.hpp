/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakegon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 00:50:07 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/10/01 20:57:48 by mmakegon         ###   ########.fr       */
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
		explicit DiamondTrap( std::string name );
		explicit DiamondTrap( const DiamondTrap &copy);
		DiamondTrap& operator=( const DiamondTrap &copy );
		~DiamondTrap();

		void		attack(const std::string &target);
		void		whoAmI( void );
		std::string	get_name();
};

#endif
