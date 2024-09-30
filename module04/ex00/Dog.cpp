/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:15:33 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/30 15:19:30 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog() : Animal::Animal("Dog") {
	std::cout << type << ": default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) {
	*this = copy;
	std::cout << type << ": copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &copy) {
	if (this != &copy)
		this->type = copy.type;
	std::cout << this->type << ": assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog(void) {
	std::cout << type << ": destructor called" << std::endl;
}

void	Dog::makeSound(void) const {
	std::cout << type << ": Bark!" << std::endl;
}
