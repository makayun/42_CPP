/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:58:03 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/29 21:19:34 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap
{
	protected:
		bool		gate_keeper_mode;
		void		scav_init();
		void		init_ep();
		void		init_hp();
		void		init_ad();

	public:
		ScavTrap();
		explicit	ScavTrap(const std::string &in_name);
		explicit	ScavTrap(const ScavTrap &copy);
		ScavTrap&	operator=(const ScavTrap &copy);
		~ScavTrap();

		void		attack(const std::string &target);
		void		guardGate();
};

#endif

