/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:25:02 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/03 13:05:56 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define PETS_COUNT 4
#define CATS_COUNT PETS_COUNT/2
#define DOGS_COUNT PETS_COUNT-CATS_COUNT

void	print_separator(void) {
	std::cout << "\n" << std::setw(50) << std::setfill('=') << "\n" << std::endl;
}

int main()
{
	print_separator();

	{
		Animal *other_pets[PETS_COUNT] = {NULL};

		try {
			for (size_t i = 0; i < PETS_COUNT; i++) {
				if (i % 2 == 0)
					other_pets[i] = new Dog;
				else
					other_pets[i] = new Cat;
			}
		}

		catch (const std::bad_alloc& e) {
			std::cerr << "Not enough memory for your pets: " << e.what() << std::endl;

			for (size_t i = 0; i < PETS_COUNT; i++) {
				if (other_pets[i] != NULL) {
					delete other_pets[i];
					other_pets[i] = NULL;
				}
			}
			return(1);
		}

		std::cout << "\nSome nasty ideas?" << std::endl;
		other_pets[0]->setIdea("Broccoli are evil aliens", 0);
		*other_pets[1] = *other_pets[0];
		std::cout << other_pets[1]->getType() + ": " << other_pets[1]->getIdea(0) + "\n" << std::endl;

		for (size_t i = 0; i < PETS_COUNT; i++)
			delete other_pets[i];
	}

	print_separator();

	{
		Cat		cat_array[CATS_COUNT];
		Dog		dog_array[DOGS_COUNT];
		Animal*	stack_pets[PETS_COUNT];

		std::cout << std::endl;

		cat_array[CATS_COUNT - 1].setIdea("Mmmmm, donuts...", IDEAS_MAX - 1);

		for (size_t i = 0; i < CATS_COUNT; i++)
			stack_pets[i] = &cat_array[i];
		for (size_t i = CATS_COUNT; i < PETS_COUNT; i++)
			stack_pets[i] = &dog_array[i - CATS_COUNT];

		std::cout << std::endl;

		for (size_t i = 0; i < PETS_COUNT; i++)
			stack_pets[i]->makeSound();

		std::cout	<< "\nWhat are you thinking about, Mr. Last Cat?\n"
					<< stack_pets[CATS_COUNT - 1]->getType() + ": "
					<< stack_pets[CATS_COUNT - 1]->getIdea(IDEAS_MAX - 1) << std::endl;
		std::cout	<< "Share it with Mr. Last Dog, please." << std::endl;
		*stack_pets[PETS_COUNT - 1] = *stack_pets[CATS_COUNT - 1];
		std::cout	<< "Tell us now, Mr. Last Dog\n"
					<< stack_pets[PETS_COUNT - 1]->getType() + ": "
					<< stack_pets[PETS_COUNT - 1]->getIdea(IDEAS_MAX - 1) + "\n" << std::endl;

		for (size_t i = 0; i < PETS_COUNT; i++)
			stack_pets[i]->makeSound();

		std::cout << std::endl;

		stack_pets[PETS_COUNT - 1]->setIdea("I'm the fairest of them all!", IDEAS_MAX); // out of range, so it's a BAD IDEA

		std::cout << std::endl;
	}

	print_separator();

	// Animal dead;
	// (void) dead;

	return 0;
}
