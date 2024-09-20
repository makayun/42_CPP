/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 01:32:28 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/19 03:22:55 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	std::cout << std::endl;

	{
		Weapon	knife = Weapon("old rusty knife");
		HumanA bob("Bob", knife);

		bob.attack();
		knife.setType("new shiny dagger");
		bob.attack();
	}

	std::cout << std::endl;

	{
		Weapon	knife = Weapon("old rusty knife");
		HumanB	jim("Jim");
		HumanB	bob("Bob", knife);

		jim.attack();
		bob.attack();
		jim.setWeapon(knife);
		jim.attack();
		bob.attack();
		knife.setType("new shiny dagger");
		jim.attack();
		bob.attack();
	}
	
	std::cout << std::endl;

	{
		Weapon	nothing("");
		Weapon	knife("old rusty knife");
		
		HumanB	strongarm("Armstrong");
		HumanA	unarmed_noname("", nothing);

		strongarm.attack();
		unarmed_noname.attack();
		strongarm.setWeapon(nothing);
		strongarm.attack();
		unarmed_noname.setWeapon(knife);
		strongarm.setWeapon(knife);
		unarmed_noname.attack();
		strongarm.attack();
	}
}
