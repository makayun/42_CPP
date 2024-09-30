/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:58:03 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/29 21:24:42 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap
{
	protected:
		void		frag_init();
		void		init_ep();
		void		init_hp();
		void		init_ad();

	public:
		FragTrap();
		explicit	FragTrap(const std::string &in_name);
		explicit	FragTrap(const FragTrap &copy);
		FragTrap&	operator=(const FragTrap &copy);
		~FragTrap();

		void attack(const std::string &target);
		void highFivesGuys(void);
};

#endif

