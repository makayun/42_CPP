/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:09:02 by mmakegon          #+#    #+#             */
/*   Updated: 2024/10/14 10:27:53 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : type("empty") {
}

AMateria::AMateria(std::string const& in_type) {
	this->type = in_type;
}

AMateria::AMateria(const AMateria &copy) {
	*this = copy;
}

AMateria &AMateria::operator=(const AMateria &copy) {
	(void)copy;
	return (*this);
}

AMateria::~AMateria(void) {
}

std::string const& AMateria::getType() const {
	return (this->type);
}

void AMateria::use(ICharacter& target) {
	(void)target;
}
