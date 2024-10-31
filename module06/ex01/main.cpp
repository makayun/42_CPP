/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:46:51 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/31 18:23:59 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Data.h"
#include "Serializer.hpp"

#define NEW_SECTION std::cout << "\n" << std::setw(50) << std::setfill('=') << "\n" << std::endl;
#define PRINT_DATA(x) std::cout << #x << ": " << x->i << ", " << x->j << std::endl;
#define PRINT_VAR(x) std::cout << #x << ": " << x << std::endl;

int main() {
	Data			a = {42,-13};
	Data			b = {80,-80};
	Data*			a_ptr = &a;
	Data*			b_ptr = &b;
	uintptr_t		raw;

	NEW_SECTION

	PRINT_VAR(a_ptr)
	PRINT_VAR(b_ptr)

	PRINT_DATA(a_ptr)
	PRINT_DATA(b_ptr)

	NEW_SECTION

	raw = Serializer::serialize(a_ptr);
	PRINT_VAR(raw)

	NEW_SECTION

	b_ptr = Serializer::deserialize(raw);

	PRINT_VAR(a_ptr)
	PRINT_VAR(b_ptr)

	PRINT_DATA(a_ptr)
	PRINT_DATA(b_ptr)

	NEW_SECTION

	raw = Serializer::serialize(&b);
	b_ptr = Serializer::deserialize(raw);

	PRINT_VAR(a_ptr)
	PRINT_VAR(b_ptr)

	PRINT_DATA(a_ptr)
	PRINT_DATA(b_ptr)

	NEW_SECTION

	raw += sizeof(int);
	unsigned int* i = reinterpret_cast<unsigned int*>(Serializer::deserialize(raw));
	*i = 4242;
	PRINT_DATA(b_ptr)

	NEW_SECTION
}
