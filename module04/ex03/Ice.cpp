/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakegon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:56:46 by mmakegon          #+#    #+#             */
/*   Updated: 2024/10/07 13:10:51 by mmakegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
}

Ice::Ice(const Ice &copy) {
	*this = copy;
}

Ice &Ice::operator=(const Ice &copy) {
	(void)copy;
	return (*this);
}

Ice::~Ice(void) {
}

void Ice::use(ICharacter& target) {
	std::string temp = this->type;
	temp[0] = (char)toupper(temp[0]);

	std::cout << temp << ": \'*shoots an ice bolt at " << target.getName() << " *\'" << std::endl;
}

Ice* Ice::clone(void) const {
	return (new Ice(*this));
}
