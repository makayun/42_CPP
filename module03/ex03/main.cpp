/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakegon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:31:00 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/29 09:31:38 by mmakegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap	robot_one( "Bender" );
	std::cout << std::endl;

	DiamondTrap	robot_two( "" );
	std::cout << std::endl;

	DiamondTrap	robot_three( robot_one );
	std::cout << std::endl;

	DiamondTrap	robot_four( DiamondTrap("Eleanore") );
	std::cout << std::endl;

	robot_two = DiamondTrap("Anette");
	std::cout << std::endl;

	robot_three.whoAmI();
	std::cout << std::endl;

	return (0);
}
