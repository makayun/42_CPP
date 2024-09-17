/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:07:24 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/17 15:59:14 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N == 0)
	{
		std::cout	<< std::endl
					<< "Ok, if that's what you want..."
					<< std::endl;
	}
	else if (N < 0)
	{
		std::cout	<< std::endl
					<< "Nononono"
					<< std::endl;
		return (NULL);
	}

	// void* rawMemory = operator new[](N * sizeof(Zombie)); // good way
	// Zombie* horde = static_cast<Zombie*>(rawMemory); // continue the good way
	// Zombie *horde = (Zombie *)rawMemory; // bad continuation

	Zombie	*horde = (Zombie *) operator new[](N * sizeof(Zombie)); // the worst way!!! =)

	if (horde == NULL)
		return (NULL);
	if (name.empty())
	{
		for (int i = 0; i < N; ++i)
			new (&horde[i]) Zombie();
		std::cout << "The horde is risen, milord!" << std::endl;
	}

	else
	{
		for (int i = 0; i < N; ++i)
			new (&horde[i]) Zombie(name);
		std::cout << "The horde is risen, milord!" << std::endl;
	}
	return (horde);
}
