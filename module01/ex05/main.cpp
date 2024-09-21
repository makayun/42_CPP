/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:41:30 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/20 15:14:40 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Harl.hpp"

void fancy_separator( void )
{
	std::cout << "\n" << std::setfill('=') << std::setw(50) << "\n" << std::endl;
}

int main()
{
	Harl harl;

	fancy_separator();

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("blahblah");

	fancy_separator();

	std::string arg;
	char *str;

	harl.complain("");
	harl.complain(arg);
	harl.complain(str);
	harl.complain(nullptr);

	fancy_separator();

	arg = "DEBUG";
	harl.complain(arg);
	harl.complain(std::string("ERROR"));

	fancy_separator();
}
