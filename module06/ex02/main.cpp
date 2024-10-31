/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:36:57 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/31 18:31:44 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
	static int random_var;
	uintptr_t	random_addr = reinterpret_cast<uintptr_t>(&random_var);

	unsigned i = random_addr % 3;
	switch (i)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			return NULL;
	}
}

void identify(Base* p) {
	if (p)
	{
		const std::string output = "ABC";
		Base*	array[3] = {dynamic_cast<A*>(p), dynamic_cast<B*>(p), dynamic_cast<C*>(p)};

		for (size_t i = 0; i < output.size(); i++)
			if (array[i]) {
				std::cout << output[i] << std::endl;
				return ;
			}
		std::cout << "None of known sub-classes" << std::endl;
	}
	else
		std::cout << "NULL" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << 'A' << std::endl;
	}
	catch(const std::bad_cast& e)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << 'B' << std::endl;
		}
		catch(const std::bad_cast& e)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << 'C' << std::endl;
			}
			catch(const std::bad_cast& e)
			{
				std::cout << "None of known sub-classes" << std::endl;
			}
		}
	}
}

int main() {
	Base* ptr = generate();

	identify(ptr);
	if (ptr)
		identify(*ptr);
	delete ptr;
	return(42);
}
