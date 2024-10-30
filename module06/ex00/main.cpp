/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:01:29 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/30 14:01:42 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		std::cout << "Usage: \"" << argv[0] << " <some literal in its most common form>\"" << std::endl;
	else {
		std::string input(argv[1]);
		ScalarConverter::convert(input);
	}
	return (42);
}
