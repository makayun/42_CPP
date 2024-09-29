/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakegon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:58:03 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/29 09:47:13 by mmakegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap
{
	private:
		void		frag_init();

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

