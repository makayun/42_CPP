/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2524/09/12 15:33:50 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/13 19:29:02 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	print_instructions(void)
{
	std::cout << "\nAvailable commands:\n" << std::setfill('.') << std::endl;

	std::cout << std::left << std::setw(25) << "Add a new contact"
			<< std::right << std::setw(10) << "ADD" << std::endl;

	std::cout << std::left << std::setw(25) << "Search in the book"
			<< std::right << std::setw(10) << "SEARCH" << std::endl;

	std::cout << std::left << std::setw(25) << "Print whole book"
			<< std::right << std::setw(10) << "BOOK" << std::endl;

	std::cout << std::left << std::setw(25) << "Print the book and exit"
			<< std::right << std::setw(10) << "EXIT" << std::endl;
			
	std::cout << std::setfill(' ') << std::endl;
}

int main()
{
	PhoneBook	my_book;
	std::string	input;

	print_instructions();

	while (1)
	{
		std::cout << "Enter a command:" << std::endl;
		std::cin >> input;
		if (input == "ADD")
		{
			if (my_book.add_contact() == ERROR)
				return (EXIT_FAILURE);
		}
		else if (input == "SEARCH")
			my_book.search();
		else if (input == "EXIT")
			break ;
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
