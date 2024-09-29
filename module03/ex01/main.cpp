/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakegon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:31:00 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/29 09:58:21 by mmakegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap	robot_one( "Bender" );
	ScavTrap	robot_two( "Calculon" );

	std::cout << std::endl;

	robot_one.beRepaired( 10 );
	robot_two.beRepaired( 10 );

	std::cout << std::endl;

	robot_one.attack( robot_two.get_name() );
	robot_two.takeDamage( robot_one.get_stat(ATTACK_DAMAGE) );

	std::cout << std::endl;

	robot_two.attack( robot_one.get_name() );
	robot_one.takeDamage( robot_two.get_stat(ATTACK_DAMAGE) );

	std::cout << std::endl;

	robot_one.attack( robot_two.get_name() );
	robot_one.beRepaired( 10 );
	robot_one.beRepaired( 10 );
	robot_one.beRepaired( 10 );
	// none of this will happen

	ScavTrap	robot_three( "" );
	robot_three = robot_two;
	ClapTrap	robot_four( robot_one );

	std::cout << std::endl;

	robot_four.attack( robot_three.get_name() ); // Won't happen, because he copied a destroyed one
	robot_three.attack( robot_two.get_name() );
	robot_two.takeDamage( robot_three.get_stat( ATTACK_DAMAGE ) );

	std::cout << std::endl;

	ScavTrap	robot_five( "Eleanore" );
	robot_five.guardGate();

	std::cout << std::endl;

	return (0);
}
