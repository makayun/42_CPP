/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:07:50 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/30 16:08:13 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:33:11 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/30 15:19:13 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("A really wrong animal") {
	std::cout	<< WRA_COLOR << type << RES_COLOR
				<< ": default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &in_type) : type(in_type) {
	std::string temp = type;

	if (temp != "A really wrong animal")
		temp.append("'s base class");
	std::cout	<< WRA_COLOR << temp << RES_COLOR
				<< ": constructor with an argument called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	*this = copy;

	std::string temp = this->type;

	if (temp != "A really wrong animal")
		temp.append("'s base class");

	std::cout	<< WRA_COLOR << temp << RES_COLOR
				<< ": copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy) {
	if (this != &copy)
		this->type = copy.type;

	std::string temp = this->type;

	if (temp != "A really wrong animal")
		temp.append("'s base class");

	std::cout	<< WRA_COLOR << temp << RES_COLOR
				<< ": assignment operator called" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal(void) {
	std::string temp = type;

	if (temp != "A really wrong animal")
		temp.append("'s base class");

	std::cout	<< WRA_COLOR << temp << RES_COLOR
				<< ": destructor called" << std::endl;
}

const std::string WrongAnimal::getType(void) const {
	return (type);
}


void	WrongAnimal::makeSound(void) const {
	std::cout	<< WRA_COLOR << type << RES_COLOR
				<< ": your ears are just bleeding now" << std::endl;
}
