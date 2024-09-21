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

int main()
{
	Harl		harl;
	std::string	input;

	std::cout << "Enter message level:\n( DEBUG / INFO / WARNING / ERROR )" << std::endl;
	
	while (input.empty() && std::cin.good())
		std::getline(std::cin, input);

	harl.complain(input);
}
