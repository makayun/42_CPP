/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:07:57 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/30 16:14:08 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal::WrongAnimal("Nasty cat") {
	std::cout	<< WRC_COLOR << type << RES_COLOR
				<< ": default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) {
	*this = copy;
	std::cout	<< WRC_COLOR << type << RES_COLOR
				<< ": copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &copy) {
	if (this != &copy)
		this->type = copy.type;
	std::cout	<< WRC_COLOR << this->type << RES_COLOR
				<< ": assignment operator called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void) {
	std::cout	<< WRC_COLOR << type << RES_COLOR
				<< ": destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const {
	std::cout	<< WRC_COLOR << type << RES_COLOR
				<< ": BUEGH!" << std::endl;
}
