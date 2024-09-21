/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 01:10:01 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/19 02:38:49 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;
	
	public:
		explicit HumanB (const std::string &in_name);
		HumanB (const std::string &in_name, Weapon &in_weapon);
		~HumanB ( void );
		int	setWeapon(Weapon &new_weapon);
		int	attack ( void );
};

#endif
