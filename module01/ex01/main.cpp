/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:16:07 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/17 16:06:00 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "Zombie.hpp"

int	bad_thing( void )
{
	std::cout << "Something went really wrong..." << std::endl;
	return (-1);
}

int horde_process(std::string greeting, std::string name, int size)
{
	std::cout	<< std::endl
				<< greeting + "\n"
				<< std::endl;

	Zombie	*horde = zombieHorde(size, name);

	if (!horde)
		return (bad_thing());

	std::cout	<< std::endl
				<< "Roar, my majestic horde!\n"
				<< std::endl;

	for (int i = 0; i < size; i++)
		horde[i].announce();

	std::cout	<< std::endl
				<< "Now rest, all of you!\n"
				<< std::endl;

	for (int i = 0; i < size; i++)
		horde[i].~Zombie();

	operator delete[](horde);

	return (1);
}

int	main()
{
	int medium = 8;
	int tiny = 1;
	int huge = 10000;

	std::cout << std::setfill('=') << std::setw(50) << "=" << std::endl;
	horde_process("HUUUGE!", "Mr Big", huge);

	std::cout << std::setfill('=') << std::setw(50) << "=" << std::endl;
	horde_process("Rise, my sweet zombies!", "Bob", medium);

	std::cout << std::setfill('=') << std::setw(50) << "=" << std::endl;
	horde_process("Try a tiny horde?", "Casey", tiny);

	std::cout << std::setfill('=') << std::setw(50) << "=" << std::endl;
	horde_process("Try an empty horde?", "Kate", 0);

	std::cout << std::setfill('=') << std::setw(50) << "=" << std::endl;
	horde_process("Go crazy?", "", medium);

	std::cout << std::setfill('=') << std::setw(50) << "=" << std::endl;
	horde_process("More crazy?", "HELP", -1);

	return (0);
}
