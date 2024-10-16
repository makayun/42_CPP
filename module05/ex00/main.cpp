/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:01:18 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/16 13:42:18 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Bureaucrat.hpp"

#ifndef COLOR_CYAN
#define COLOR_CYAN "\033[0;36m"
#endif

#ifndef COLOR_RES
#define COLOR_RES "\033[0m"
#endif

#define NEW_SECTION std::cout << "\n" << std::setw(50) << std::setfill('=') << "\n" << std::endl;

int main()
{
	Bureaucrat first("Carl", 1);
	Bureaucrat second("Bob", 150);

	NEW_SECTION

	std::cout	<< first << std::endl
				<< second << std::endl;

	NEW_SECTION

	try
	{
		first.demote();
		first.demote(40);
		first.demote(108);
		first.promote(150);
		std::cout	<< COLOR_CYAN
					<< "This won't be printed, because the program will jump to the catch block"
					<< COLOR_RES << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout	<< COLOR_CYAN
					<< "We caught an exception and printed it, but we also can do here whatever we want"
					<< COLOR_RES << std::endl;
	}

	NEW_SECTION

	std::cout	<< first << "\n"
				<< second << "\n"
				<< COLOR_CYAN
				<< "Carl didn't change his grade, but the program still goes on, because we managed the exception in the catch block"
				<< COLOR_RES << std::endl;


	NEW_SECTION

	try
	{
		second.promote(149);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << "This we won't see, because no exceptiond was thrown and so we've never entered this catch block" << std::endl;
	}

	NEW_SECTION

	try
	{
		Bureaucrat third("Kate", 151);
		third.promote(150);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	NEW_SECTION

	std::cout << second << std::endl;
	second.promote();
	std::cout << "This you will never see, because an exception terminated the program" << std::endl;
}
