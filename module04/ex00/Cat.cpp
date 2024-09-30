/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:45:55 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/30 16:38:40 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal::Animal("Cat") {
	std::cout	<< CAT_COLOR << type << RES_COLOR
				<< ": default constructor called" << std::endl;
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
