/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:01:18 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/18 14:36:39 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

#define NEW_SECTION std::cout << "\n" << std::setw(50) << std::setfill('=') << "\n" << std::endl;
#define PRINT_VAR(x) std::cout << #x << ": " << x << std::endl;

int main()
{
	Bureaucrat	first("Carl", 1);
	PresidentialPardonForm pardon_one("Steve Rogers");
	PresidentialPardonForm pardon_two("Natasha Romanoff");


	PRINT_VAR(pardon_one);
	try
	{
		first.signForm(pardon_one);
		pardon_one.execute(first);
		pardon_two.execute(first);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
