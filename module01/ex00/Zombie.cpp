/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:06:31 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/18 00:51:05 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string	Zombie::set_color( void )
{
	const std::string	colors[5] = {
		"\033[31m", // Red
		"\033[32m", // Green
		"\033[33m", // Yellow
		"\033[34m", // Blue
		"\033[35m", // Magenta
	};
	int		index;

	index = 2 * this->name[0] % 5;
	return (colors[index]);
}

void	Zombie::announce( void )
{
	std::cout	<< this->color
				<< this->name
				<< ": BraiiiiiiinnnzzzZ..."
				<< COLOR_RES
				<< std::endl;
}

void	Zombie::nameless_zombie( void )
{
	this->name = "Noname";
	this->color = this->set_color();
	std::cout	<< this->color
				<< "* this poor creature doesn't remember its name *"
				<< COLOR_RES
				<< std::endl;
}

Zombie::Zombie(const std::string &input_name)
{

	if (input_name.empty())
		this->nameless_zombie();
	else
	{
		this->name = input_name;
		this->color = this->set_color();
		std::cout	<< this->color
					<< this->name
					<< " is alive again!"
					<< COLOR_RES
					<< std::endl;
	}
}

Zombie::Zombie( void )
{
	this->color = this->set_color();
	this->nameless_zombie();
}

Zombie::~Zombie( void )
{
	std::cout	<< this->color
				<< this->name
				<< ": No braiiiiiiinnnzzzZ???"
				<< COLOR_RES
				<< std::endl;
}
