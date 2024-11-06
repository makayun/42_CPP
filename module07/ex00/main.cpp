/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:59:48 by mmakagon          #+#    #+#             */
/*   Updated: 2024/11/06 11:00:53 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "whatever.hpp"

#define NEW_SECTION std::cout << "\n" << std::setw(50) << std::setfill('=') << "\n" << std::endl;
#define PRINT_VAR(x) std::cout << #x << ": " << x << std::endl;

int main()
{
	NEW_SECTION

	int i = 42;
	int j = 13;

	std::cout << "Original ints:" << std::endl;
	PRINT_VAR(i)
	PRINT_VAR(j)

	whatever::swap(i, j);

	std::cout << "\nInts afters swap" << std::endl;
	PRINT_VAR(i)
	PRINT_VAR(j)

	NEW_SECTION

	PRINT_VAR(whatever::max('a', 'z'))

	NEW_SECTION

	std::string str1 = "StringA";
	std::string str2 = "StringZ";

	PRINT_VAR(str1)
	PRINT_VAR(str2)
	PRINT_VAR(whatever::min(str1, str2));

	NEW_SECTION

	// PRINT_VAR(whatever::max(42.42, '*'));
	// PRINT_VAR(whatever::max(42.42, (double)'*'));
}
