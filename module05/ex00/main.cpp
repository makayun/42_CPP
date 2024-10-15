/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:01:18 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/14 15:32:00 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat first("Carl", 1);
	Bureaucrat second("Bob", 150);

	std::cout	<< first << std::endl
				<< second << std::endl;

	try
	{
		Bureaucrat("Kate", -1);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		first.promote();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
