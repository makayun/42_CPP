/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:33:11 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/03 12:55:02 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Unknown animal") {
	std::cout	<< ANML_COLOR << type << RES_COLOR
				<< ": default constructor called" << std::endl;
	brain = new Brain;
}

Animal::Animal(const std::string &in_type) : type(in_type) {
	std::string temp = type;

	if (temp != "Unknown animal")
		temp.append("'s base class");

	brain = new Brain;

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

	if (this->brain)
		delete this->brain;

	if (copy.brain)
			this->brain = new Brain(*copy.brain);
		else
			this->brain = NULL;

	return (*this);
}

Animal::~Animal(void) {
	std::string temp = type;

	if (temp != "Unknown animal")
		temp.append("'s base class");

	delete brain;

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

const std::string	Animal::getIdea(size_t id) const {
	if (brain)
		return (brain->getIdea(id));
	else
		return ("NO BRAIN FOUND");
}

void	Animal::setIdea(const std::string &in_idea, size_t id) {
	if (brain)
		brain->setIdea(in_idea, id);
}

