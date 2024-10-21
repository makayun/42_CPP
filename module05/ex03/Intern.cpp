/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 01:17:46 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/19 02:26:14 by mmakagon         ###   ########.fr       */
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

AForm*	Intern::makeForm(const std::string& in_type, const std::string& in_target) {
	PresidentialPardonForm	a(in_target);
	RobotomyRequestForm		b(in_target);
	ShrubberyCreationForm	c(in_target);
	AForm	*forms[3] = {&a, &b, &c};
	const std::string types[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int i = 0; i < 3; i++)
		if (in_type == types[i]) {
			std::cout << "Intern creates form " << types[i] << std::endl;
			
		}
	std::cerr << "This intern doesn't know that type of form...";
}
