/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 01:17:46 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/21 13:04:46 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
}

Intern::Intern(const Intern &copy) {
	*this = copy;
}

Intern	&Intern::operator=(const Intern &copy) {
	(void)copy;
	return (*this);
}

Intern::~Intern(void) {
}

AForm* Intern::makeForm(const std::string& in_type, const std::string& in_target) {
	
}

