/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:16:07 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/17 23:44:12 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

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
	return (0);
}
