/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:31:00 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/29 21:04:22 by mmakagon         ###   ########.fr       */
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

	robot_one.whoAmI();
	std::cout << std::endl;

	robot_two.whoAmI();
	std::cout << std::endl;

	robot_three.whoAmI();
	std::cout << std::endl;

	robot_four.whoAmI();
	std::cout << std::endl;

	return (0);
}
