/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:19:10 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/21 14:16:55 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define NEW_SECTION std::cout << "\n" << std::setw(50) << std::setfill('=') << "\n" << std::endl;
#define PRINT_VAR(x) std::cout << #x << ": " << x << std::endl;

int main()
{
	Bureaucrat	first("Carl", 1);
	PresidentialPardonForm pardon_one("Steve Rogers");
	PresidentialPardonForm pardon_two("Natasha Romanoff");

	NEW_SECTION

	PRINT_VAR(first);
	PRINT_VAR(pardon_one);
	PRINT_VAR(pardon_two);

	NEW_SECTION

	first.signForm(pardon_one);
	PRINT_VAR(pardon_one);
	first.executeForm(pardon_one);

	pardon_one = pardon_two;
	PRINT_VAR(pardon_one);

	first.signForm(pardon_one);
	first.executeForm(pardon_one);
	first.executeForm(pardon_two);

	NEW_SECTION

	ShrubberyCreationForm trees("Backyard");
	PRINT_VAR(trees);
	first.signForm(trees);
	first.executeForm(trees);
	// trees.drawTrees(std::cout, 15, 6);

	NEW_SECTION

	RobotomyRequestForm request("Fry");
	PRINT_VAR(request);
	first.signForm(request);
	first.executeForm(request);

	NEW_SECTION
}
