/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakegon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:33:11 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/02 09:53:29 by mmakegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

void Animal::growBrain(void)
{
	try {
		brain = new Brain;
	}
	catch (std::bad_alloc& e) {
		std::cerr << "Failed to allocate brain: " << e.what() << std::endl;
	}
}

Animal::Animal() : type("Unknown animal") {
	std::cout	<< ANML_COLOR << type << RES_COLOR
				<< ": default constructor called" << std::endl;
	growBrain();
}

Animal::Animal(const std::string &in_type) : type(in_type) {
	std::string temp = type;

	if (temp != "Unknown animal")
		temp.append("'s base class");
	std::cout	<< ANML_COLOR << temp << RES_COLOR
				<< ": constructor with an argument called" << std::endl;
	growBrain();
}

Animal::Animal(const Animal &copy) {
	*this = copy;

	if (copy.brain)
		this->brain = new Brain(*copy.brain);

	std::string temp = this->type;

	if (temp != "Unknown animal")
		temp.append("'s base class");

	std::cout	<< ANML_COLOR << temp << RES_COLOR
				<< ": copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &copy) {
	if (this != &copy) {
		// this->type = copy.type;

		if (this->brain)
			delete this->brain;

		if (copy.brain)
			this->brain = new Brain(*copy.brain);
		else
			this->brain = nullptr;
	}

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
	// else
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

Brain*	Animal::findBrain(void) {
	return brain;
}

const std::string	Animal::getIdea(size_t id) const {
	return (brain->getIdea(id));
}

void	Animal::setIdea(const std::string &in_idea, size_t id) {
	brain->setIdea(in_idea, id);
}
