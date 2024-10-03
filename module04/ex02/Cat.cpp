/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakegon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:45:55 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/02 13:27:42 by mmakegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal::Animal("Cat") {
	std::cout	<< CAT_COLOR << type << RES_COLOR
				<< ": default constructor called" << std::endl;
	growBrain();
}

Cat::Cat(const Cat &copy) {
	*this = copy;

	if (copy.brain)
		this->brain = new Brain(*copy.brain);

	std::cout	<< CAT_COLOR << type << RES_COLOR
				<< ": copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &copy) {
	if (this != &copy) {
		// this->type = copy.type;

		if (this->brain)
			delete this->brain;

		if (copy.brain)
			this->brain = new Brain(*copy.brain);
		else
			this->brain = nullptr;
	}
	std::cout	<< CAT_COLOR << this->type << RES_COLOR
				<< ": assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat(void) {
	std::cout	<< CAT_COLOR << type << RES_COLOR
				<< ": destructor called" << std::endl;
}

void	Cat::makeSound(void) const {
	std::cout	<< CAT_COLOR << type << RES_COLOR
				<< ": MEEEOOOOOWWWWWWWW!!!!" << std::endl;
}
