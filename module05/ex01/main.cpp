/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:01:18 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/16 13:55:55 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"
#include "Form.hpp"

#ifndef COLOR_CYAN
#define COLOR_CYAN "\033[0;36m"
#endif

#ifndef COLOR_RES
#define COLOR_RES "\033[0m"
#endif

#define NEW_SECTION std::cout << "\n" << std::setw(50) << std::setfill('=') << "\n" << std::endl;

int main()
{
	Bureaucrat	first("Carl", 1);
	Bureaucrat	second("Bob", 150);
	Form		form_one("Construction allowance", 2, 150);
	Form		form_two("Busking licence", 2, 150);

	NEW_SECTION

	std::cout	<< first << "\n"
				<< second << std::endl;

	std::cout	<< "\nForm one: " << form_one.getName()
				<< "\nMinimal grade required to sign it: " << form_one.getSignGrade()
				<< std::endl;

	std::cout	<< "\nForm two: " << form_two.getName()
				<< "\nMinimal grade required to sign it: " << form_two.getSignGrade()
				<< std::endl;

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
