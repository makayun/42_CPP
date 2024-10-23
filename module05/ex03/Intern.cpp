/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 01:17:46 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/23 09:22:00 by mmakagon         ###   ########.fr       */
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

Form* Intern::makeForm(const std::string& in_type, const std::string& in_target) {
	const std::string types[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	std::string	messages[2] = {"Intern creates ",
							COLOR_RED "Intern doesn't know this type of form: " COLOR_RES};
	Form		*ret = NULL;
	int 		i = 0;

	while (i < 3 && in_type.compare(types[i]))
		i++;

	switch (i)
	{
		case 0:
			ret = new PresidentialPardonForm(in_target);
			break;
		case 1:
			ret = new RobotomyRequestForm(in_target);
			break;
		case 2:
			ret = new ShrubberyCreationForm(in_target);
			break;
		default:
			break;
	}

	std::cout << messages[ret == NULL] << in_type << std::endl;
	return (ret);
}

