/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:45:55 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/30 15:28:19 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal::Animal("Cat") {
	std::cout << type << ": default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) {
	*this = copy;
	std::cout << type << ": copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &copy) {
	if (this != &copy)
		this->type = copy.type;
	std::cout << this->type << ": assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat(void) {
	std::cout << type << ": destructor called" << std::endl;
}

void	Cat::makeSound(void) const {
	std::cout << type << ": MEEEOOOOOWWWWWWWW!!!!" << std::endl;
}
