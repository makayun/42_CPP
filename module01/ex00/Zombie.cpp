/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:06:31 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/17 13:49:56 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string	Zombie::set_color( void )
{
	std::string	colors[5] = {
		"\033[31m", // Red
		"\033[32m", // Green
		"\033[33m", // Yellow
		"\033[34m", // Blue
		"\033[35m", // Magenta
	};
	int		number;

	number = 2 * this->name[0] % 5;
	return (colors[number]);
}

void	Zombie::announce( void )
{
	std::cout	<< this->color
				<< this->name
				<< ": BraiiiiiiinnnzzzZ..."
				<< COLOR_RES
				<< std::endl;
}

Zombie::Zombie(std::string input_name) : name(input_name)
{
	this->color = this->set_color();
	std::cout	<< this->color
				<< this->name
				<< " is alive again!"
				<< COLOR_RES
				<< std::endl;
}

Zombie::Zombie( void ) : name("Noname")
{
	this->color = this->set_color();
	std::cout	<< this->color
				<< "* this poor creature doesn't remember its name *"
				<< COLOR_RES
				<< std::endl;
}

Zombie::~Zombie( void )
{
	std::cout	<< this->color
				<< this->name
				<< ": No braiiiiiiinnnzzzZ???"
				<< COLOR_RES
				<< std::endl;
}
