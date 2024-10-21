/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:19:10 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/21 14:17:44 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#define NEW_SECTION std::cout << "\n" << std::setw(50) << std::setfill('=') << "\n" << std::endl;
#define PRINT_VAR(x) std::cout << #x << ": " << x << std::endl;

int main()
{
	Bureaucrat	king("Charles", 1);
	Intern		someRandomIntern;
	Form*		rrf;
	Form*		frf;

	NEW_SECTION

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf) {
		PRINT_VAR(*rrf);
		king.signForm(*rrf);
		king.executeForm(*rrf);
	}

	NEW_SECTION

	frf = someRandomIntern.makeForm("42 freeze request", "Max");
	if (frf) {
		PRINT_VAR(*frf);
		king.signForm(*frf);
		king.executeForm(*frf);
	}

	NEW_SECTION

	delete rrf;
	delete frf;
}
