/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:33:11 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/30 16:36:17 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Unknown animal") {
	std::cout	<< ANML_COLOR << type << RES_COLOR
				<< ": default constructor called" << std::endl;
}

Animal::Animal(const std::string &in_type) : type(in_type) {
	std::string temp = type;

	if (temp != "Unknown animal")
		temp.append("'s base class");
	std::cout	<< ANML_COLOR << temp << RES_COLOR
				<< ": constructor with an argument called" << std::endl;
}

Animal::Animal(const Animal &copy) {
	*this = copy;

	std::string temp = this->type;

	if (temp != "Unknown animal")
		temp.append("'s base class");

	std::cout	<< ANML_COLOR << temp << RES_COLOR
				<< ": copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &copy) {
	if (this != &copy)
		this->type = copy.type;

	std::string temp = this->type;

	if (temp != "Unknown animal")
		temp.append("'s base class");

	std::cout	<< ANML_COLOR << temp << RES_COLOR
				<< ": assignment operator called" << std::endl;
	return (*this);
}

Animal::~Animal(void) {
	std::string temp = type;

	if (temp != "Unknown animal")
		temp.append("'s base class");

	std::cout	<< ANML_COLOR << temp << RES_COLOR
				<< ": destructor called" << std::endl;
}

const std::string Animal::getType(void) const {
	return (type);
}

void	Animal::makeSound(void) const {
	std::cout	<< ANML_COLOR << type << RES_COLOR
				<< ": inaudible ultrasonic noise" << std::endl;
}
