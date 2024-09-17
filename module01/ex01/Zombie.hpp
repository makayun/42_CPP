/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:03:21 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/17 14:02:47 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

#define COLOR_RES "\033[0m"

class Zombie {

	private:
		std::string	name;
		std::string color;
		std::string set_color( void );

	public:
		Zombie ( void );
		Zombie (std::string input_name);
		~Zombie ( void );

		void		announce ( void );
};

Zombie* zombieHorde( int N, std::string name );

#endif
