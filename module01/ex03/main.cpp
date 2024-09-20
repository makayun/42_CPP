/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 01:32:28 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/20 12:48:41 by mmakagon         ###   ########.fr       */
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
		Weapon	spoon = Weapon("silver spoon");
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

		jim.setWeapon(spoon);
		bob.setWeapon(spoon);
		jim.attack();
		bob.attack();
	}

	std::cout << std::endl;

	{
		Weapon	nothing("");
		Weapon	knife("old rusty knife");

		HumanB	strongarm_b("Armstrong");
		HumanA	unarmed_noname_a("", nothing);

		strongarm_b.attack();

		unarmed_noname_a.attack();
		strongarm_b.setWeapon(nothing);
		strongarm_b.attack();

		unarmed_noname_a.setWeapon(knife);
		strongarm_b.setWeapon(knife);
		unarmed_noname_a.attack();
		strongarm_b.attack();
	}
}
