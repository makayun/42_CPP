/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:16:07 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/20 12:42:01 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "Zombie.hpp"

int	bad_thing( void )
{
	std::cout << "Something went really wrong...\n" << std::endl;
	return (-1);
}

void	print_separator( void )
{
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::endl;
}

int horde_process(const std::string &greeting, const std::string &name, int size)
{
	Zombie	*horde;

	print_separator();

	std::cout	<< "\n" + greeting + "\n"
				<< std::endl;

	horde = zombieHorde(size, name);

	if (!horde)
		return (bad_thing());

	std::cout	<< "\nRoar, my majestic horde!\n"
				<< std::endl;

	for (int i = 0; i < size; i++)
		horde[i].announce();

	std::cout	<< "\nNow rest, all of you!\n"
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
	// int huge = 10000;

	// horde_process("HUUUGE!", "Mr Big", huge); // better to output into some file...

	horde_process("Rise, my sweet zombies!", "Bob", medium);
	horde_process("Try a tiny horde?", "Casey", tiny);
	horde_process("Try an empty horde?", "Kate", 0);
	horde_process("Some serious brain damage?", "", medium);
	horde_process("Go crazy?", "HELP", -1);

	return (0);
}
