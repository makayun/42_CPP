/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:25:02 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/01 16:03:04 by mmakagon         ###   ########.fr       */
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
	const unsigned int	pets_count = 8;
	void				*rawMemory = operator new[](pets_count * sizeof(Animal));
	Animal				*home_zoo = static_cast<Animal*>(rawMemory);

	for (size_t i = 0; i < 7; i++)
	{
		if (i % 2 == 0)
			new (&home_zoo[i]) Dog;
		else
			new (&home_zoo[i]) Cat;
	}

	for (size_t i = 0; i <7; i++)
		home_zoo[i].~Animal();

	operator delete[](home_zoo);

	return 0;
}
