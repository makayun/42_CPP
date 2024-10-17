/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakegon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:01:18 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/17 08:41:25 by mmakegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define NEW_SECTION std::cout << "\n" << std::setw(50) << std::setfill('=') << "\n" << std::endl;
#define PRINT_VAR(x) std::cout << #x << ": " << x << std::endl;

int main()
{
	Bureaucrat	first("Carl", 1);
	Bureaucrat	second("Bob", 150);
	Form		form_one("Construction allowance", 1, 150);
	Form		form_two("Busking licence", 2, 150);

	NEW_SECTION

	PRINT_VAR(first)
	PRINT_VAR(second)
	PRINT_VAR(form_one)
	PRINT_VAR(form_two)

	NEW_SECTION

	first.signForm(form_one);
	second.signForm(form_one);
	second.signForm(form_two);
	second.promote(148);
	second.signForm(form_two);

	NEW_SECTION

	try
	{
		Form form_three("Stupid form", 0, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	NEW_SECTION
}
