/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmakagonov <maxmakagonov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:31:00 by maxmakagono       #+#    #+#             */
/*   Updated: 2024/09/25 11:01:30 by maxmakagono      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main()
{
    ClapTrap robot_one("Bender");
    ClapTrap robot_two("Calculon");

    std::cout << std::endl;

    robot_one.beRepaired(10);
    robot_two.beRepaired(10);
    
    std::cout << std::endl;

    robot_one.attack(robot_two.get_name());
    robot_two.takeDamage(robot_one.get_stat(ATTACK_DAMAGE));

    std::cout << std::endl;

    robot_two.attack(robot_one.get_name());
    robot_one.takeDamage(robot_two.get_stat(ATTACK_DAMAGE));

    std::cout << std::endl;

    robot_two.attack(robot_one.get_name());
    robot_one.takeDamage(robot_two.get_stat(ATTACK_DAMAGE));

    std::cout << std::endl;

    robot_one.attack(robot_two.get_name());
    robot_one.beRepaired(10);
    robot_one.beRepaired(10);
    robot_one.beRepaired(10);
    // none of this will happen

    ClapTrap what("");

    std::cout << std::endl;
    
    return (0);
}
