/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakegon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:03:25 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/29 10:04:29 by mmakegon         ###   ########.fr       */
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

		std::string	set_color( const std::string &name );
		void		set_name( const std::string &in_name);
		void		set_stat( size_t stat_id, long const &in_value );
		void		clap_init( void );
		void		print_hp( void );

	public:
		ClapTrap();
		explicit			ClapTrap( const std::string &in_name );
		explicit			ClapTrap( const ClapTrap &copy );
		ClapTrap&			operator= ( const ClapTrap &copy );
		~ClapTrap();

		void				attack(const std::string& target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);

		long				get_stat( size_t stat_id ) const;
		const std::string&	get_name(void) const;

};

#endif
