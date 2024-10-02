/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakegon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:15:33 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/02 01:12:23 by mmakegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog() : Animal::Animal("Dog") {
	std::cout	<< DOG_COLOR << type << RES_COLOR
				<< ": default constructor called" << std::endl;
	growBrain();
}

Dog::Dog(const Dog &copy) {
	*this = copy;
	std::cout	<< DOG_COLOR << type << RES_COLOR
				<< ": copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &copy) {
	if (this != &copy)
		this->type = copy.type;
	std::cout	<< DOG_COLOR << this->type << RES_COLOR
				<< ": assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog(void) {
	std::cout	<< DOG_COLOR << type << RES_COLOR
				<< ": destructor called" << std::endl;
}

void	Dog::makeSound(void) const {
	std::cout	<< DOG_COLOR << type << RES_COLOR
				<< ": Bark!" << std::endl;
}
