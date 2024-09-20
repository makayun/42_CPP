/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 01:38:40 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/19 03:21:45 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon		*weapon;
	
	public:
		HumanA (const std::string &in_name, Weapon &in_weapon);
		~HumanA ( void );
		int	setWeapon(Weapon &new_weapon);
		int	attack ( void );
};
