/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:16:07 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/23 11:29:56 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

void	outer_function(std::string &str)
{
	std::cout << "str address outside: " << &str << std::endl;
	std::cout << "str value outside: " << str << std::endl;

	std::cout << std::endl;

	str = "WAIT, THERE IS A BIT OF BRAIN";
	std::cout << "new str value outside: " << str << std::endl;
}

int	main()
{
	std::string			str = "HI THIS IS BRAIN";
	std::string const	*stringPTR = &str;
	std::string			&stringREF = str;

	std::cout << "str address: " << &str << std::endl;
	std::cout << "PTR address: " << stringPTR << std::endl;
	std::cout << "REF address: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "str value: " << str << std::endl;
	std::cout << "PTR value: " << *stringPTR << std::endl;
	std::cout << "REF value: " << stringREF << std::endl;

	std::cout << std::endl;

	str.clear();

	std::cout << "str value: " << str << std::endl;
	std::cout << "PTR value: " << *stringPTR << std::endl;
	std::cout << "REF value: " << stringREF << std::endl; //might be dangerous!!!

	std::cout << std::endl;

	str = "NO BRAINS LEFT";

	std::cout << "str value: " << str << std::endl;
	std::cout << "PTR value: " << *stringPTR << std::endl;
	std::cout << "REF value: " << stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "str address in main: " << &str << std::endl;

	outer_function(str);

	std::cout << "new str value in main: " << str << std::endl;
	return (0);
}
