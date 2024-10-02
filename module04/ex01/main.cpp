/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakegon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:25:02 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/02 09:50:53 by mmakegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define PETS_COUNT 5

int main()
{
	{
		const size_t		cats_size = PETS_COUNT / 2 * sizeof(Cat);
		const size_t		dogs_size = (PETS_COUNT - (PETS_COUNT / 2)) * sizeof(Dog);
		const size_t		memory_size = cats_size + dogs_size;
		void				*rawMemory = operator new[](memory_size);
		if (rawMemory == nullptr)
			return (1);
		Animal				*home_zoo = static_cast<Animal*>(rawMemory);

		std::cout << "\nCome here, my sweethearts!" << std::endl;
		try {
			for (size_t i = 0; i < PETS_COUNT; i++) {
				if (i % 2 == 0)
					new (&home_zoo[i]) Dog;
				else
					new (&home_zoo[i]) Cat;
			}
		}
		catch (const std::bad_alloc& e) {
			std::cerr << "Not enough memory for your pets: " << e.what() << std::endl;
			for (size_t i = 0; i < PETS_COUNT && &home_zoo[i] != nullptr; i++)
				delete &home_zoo[i];
		}

		std::cout << "\nWho's a good pet?" << std::endl;
		for (size_t i = 0; i < PETS_COUNT; i++)
			home_zoo[i].makeSound();

		std::cout << "\nNow you're sharing ideas?" << std::endl;
		home_zoo[0].setIdea("Broccolis are evil aliens", 0);
		home_zoo[1] = home_zoo[0];
		std::cout << home_zoo[1].getIdea(0) << std::endl;

		std::cout << std::endl;

		for (size_t i = 0; i < PETS_COUNT; i++)
			home_zoo[i].~Animal();

		operator delete[](home_zoo);

		std::cout << std::endl;
	}

	{
		Animal *another_zoo[PETS_COUNT] = {nullptr};

		try {
			for (size_t i = 0; i < PETS_COUNT; i++) {
				if (i % 2 == 0)
					another_zoo[i] = new Dog;
				else
					another_zoo[i] = new Cat;
			}
		}

		catch (const std::bad_alloc& e) {
			std::cerr << "Memory allocation failed: " << e.what() << std::endl;

			for (size_t i = 0; i < PETS_COUNT; i++) {
				if (another_zoo[i] != nullptr) {
					delete another_zoo[i];
					another_zoo[i] = nullptr;
				}
			}
		}

		for (size_t i = 0; i < PETS_COUNT; i++)
			std::cout << another_zoo[i]->findBrain() << std::endl;

		another_zoo[0]->setIdea("Broccolis are evil aliens", 0);
		*another_zoo[1] = *another_zoo[0];
		std::cout << another_zoo[1]->getIdea(0) << std::endl;

		for (size_t i = 0; i < PETS_COUNT; i++)
			delete another_zoo[i];
	}
	return 0;
}
