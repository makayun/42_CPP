/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakegon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:45:55 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/02 01:12:18 by mmakegon         ###   ########.fr       */
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
	std::cout	<< CAT_COLOR << type << RES_COLOR
				<< ": copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &copy) {
	if (this != &copy)
		this->type = copy.type;
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
