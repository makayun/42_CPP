/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakegon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:10:25 by mmakegon          #+#    #+#             */
/*   Updated: 2024/10/07 14:29:15 by mmakegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
}

Cure::Cure(const Cure &copy) : AMateria("cure") {
	*this = copy;
}

Cure &Cure::operator=(const Cure &copy) {
	(void)copy;
	return (*this);
}

Cure::~Cure(void) {
}


void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure* Cure::clone(void) const {
	return (new Cure(*this));
}
