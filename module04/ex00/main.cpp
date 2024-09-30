/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:25:02 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/30 16:57:12 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* i = new Cat();
		const Animal* j = new Dog();

		std::cout << "i's type: " << i->getType() << std::endl;
		std::cout << "j's type: " << j->getType() << std::endl;

		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete i;
		delete j;
	}
	std::cout << "\n\n" << std::endl;
	{
		WrongAnimal	wrong;

		std::cout << "type: " << wrong.getType() << std::endl;
		wrong.makeSound();
	}
	std::cout << "\n\n" << std::endl;
	{
		WrongCat	wrong;

		std::cout << "type: " << wrong.getType() << std::endl;
		wrong.makeSound();
	}

	return 0;
}
