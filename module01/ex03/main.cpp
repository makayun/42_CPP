/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 01:32:28 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/18 09:05:39 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

int main()
{
	Weapon	knife("old rusty knife");
	HumanB	jim("Jim");

	jim.attack();
	jim.setWeapon(knife);
	jim.attack();
	knife.setType("new shiny knife");
	jim.attack();
}
