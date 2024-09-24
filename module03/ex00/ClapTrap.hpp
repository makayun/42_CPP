/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:03:25 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/24 13:25:05 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ClapTrap
{
	private:
		std::string	name;
		long		hit_p;
		long		energy_p;
		long		attack_dmg;

	public:
		ClapTrap( const std::string in_name );
		ClapTrap( const ClapTrap &copy );
		ClapTrap &operator= ( const ClapTrap &copy );
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		long	get_hp( void );
		long	set_hp( long in_hp);
};
