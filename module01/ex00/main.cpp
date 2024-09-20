/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:16:07 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/18 00:51:01 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie	z1_stack("Carl");
	Zombie	z2_stack;
	Zombie	*z3_heap;
	Zombie	*z4_heap;

	std::cout	<< std::endl
				<< "Stack zombies have risen, let's rise the heap ones!\n"
				<< std::endl;

	z3_heap = newZombie("Bob");
	z4_heap = newZombie("Tiny Tyna");

	std::cout	<<std::endl
				<< "There's also some random guy, but he's weak and won't last long...\n"
				<< std::endl;

	randomChump("Felix");

	std::cout << std::endl << "Now roar, zombies!\n" << std::endl;

	z1_stack.announce();
	z2_stack.announce();
	z3_heap->announce();
	z4_heap->announce();

	std::cout << std::endl << "Now go to sleep, my sweet zombies!\n" << std::endl;

	delete (z4_heap);
	delete (z3_heap);
}
