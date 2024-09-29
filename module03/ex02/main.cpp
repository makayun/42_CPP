/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmakagonov <maxmakagonov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:31:00 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/28 00:45:51 by maxmakagono      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    {
        ClapTrap    robot_one( "Bender" );
        ScavTrap    robot_two( "Calculon" );
        FragTrap    robot_three( "" );
        ClapTrap    robot_four( robot_one );
        ScavTrap    robot_five( ScavTrap("Eleanore") );

        std::cout << std::endl;

        robot_three = FragTrap("Anette");

        std::cout << std::endl;
    }

        std::cout << "\n\n\n" << std::endl;

    {
        ClapTrap    hero("Arthur");
        ScavTrap    enemy("Dragon");
        FragTrap    healer("Merlin");

        std::cout << std::endl;

        while ((enemy.get_stat(HIT_POINTS) > 0) && (hero.get_stat(HIT_POINTS) > 0))
        {
            while (enemy.get_stat(ATTACK_DAMAGE) >= hero.get_stat(HIT_POINTS))
            {
                healer.attack(hero.get_name());
                hero.beRepaired(healer.get_stat(ATTACK_DAMAGE));
                std::cout << std::endl;
            }

            enemy.attack(hero.get_name());
            hero.takeDamage(enemy.get_stat(ATTACK_DAMAGE));

            std::cout << std::endl;

            hero.attack(enemy.get_name());
            enemy.takeDamage(hero.get_stat(ATTACK_DAMAGE));
            
            std::cout << std::endl;
        }

        std::cout << std::endl;
    }
    return (0);
}
