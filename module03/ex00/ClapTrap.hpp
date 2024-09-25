/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmakagonov <maxmakagonov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:03:25 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/25 15:22:38 by maxmakagono      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define COLOR_RES "\033[0m"

enum e_stats
{
	HIT_POINTS,
	ENERGY_POINTS,
	ATTACK_DAMAGE,
	STATS_MAX
};

class ClapTrap
{
	private:
		std::string	name;
		long		stats[STATS_MAX];
		bool		is_destroyed;
		
		std::string	set_color( const std::string &name );
		void		set_stat( size_t stat_id, long const &in_value );
		void		print_hp( void );

	public:
		explicit	ClapTrap( const std::string &in_name );
		explicit	ClapTrap( const ClapTrap &copy );
		ClapTrap&	operator= ( const ClapTrap &copy );
		~ClapTrap();

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		long		get_stat( size_t stat_id ) const;
		const std::string& get_name(void) const;

};

#endif
