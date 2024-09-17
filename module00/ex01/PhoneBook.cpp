/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:33:38 by mmakagon          #+#    #+#             */
/*   Updated: 2024/09/16 14:32:43 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): contacts_total(0) {
}

PhoneBook::~PhoneBook() {
}

int PhoneBook::add_contact(void)
{
	Contact		new_cont;
	std::string	input;

	std::cout << "Enter first name:" << std::endl;
	while (input.empty())
		std::getline(std::cin, input);
	input[0] = (char)std::toupper(input[0]);
	new_cont.set_field(FIRST_NAME, input);
	input.clear();

	std::cout << "Enter second name:" << std::endl;
	while (input.empty())
		std::getline(std::cin, input);
	input[0] = (char)std::toupper(input[0]);
	new_cont.set_field(SECOND_NAME, input);
	input.clear();

	std::cout << "Enter a nickname:\n";
	while (input.empty())
		std::getline(std::cin, input);
	new_cont.set_field(NICKNAME, input);
	input.clear();

	std::cout << "Enter phone number:\n";
	while (input.empty())
	{
		std::getline(std::cin, input);
		for (size_t j = 0; j < input.size(); j++)
			if (!isdigit(input[j]))
			{
				std::cout << "Not a number! Try again:" << std::endl;
				input.clear();
				break ;
			}
	}
	new_cont.set_field(PHONE_NUM, input);
	input.clear();

	std::cout << "Enter a secret:\n";
	while (input.empty())
		std::getline(std::cin, input);
	new_cont.set_field(SECRET, input);

	for (size_t i = MAX_CONTACTS - 1; i > 0; i--)
		this->book[i] = this->book[i - 1];
	this->book[0] = new_cont;

	this->print_head();
	this->print_contact(0);
	this->contacts_total += (this->contacts_total < MAX_CONTACTS);
	std::cout << std::endl;
	return (ALL_FINE);
}


void	PhoneBook::fancy_line(void)
{
	for (int i = 0; i < 4; i++)
		std::cout << "+" << std::setfill('-') << std::setw(10) << "-";
	std::cout << std::setfill(' ') << "+" << std::endl;
}

void	PhoneBook::fancy_field(std::string str)
{
	std::cout << "|" << std::setw(10) << str;
}

int	PhoneBook::print_head(void)
{
	std::cout << std::endl;
	fancy_line();
	fancy_field("id");
	fancy_field("first name");
	fancy_field("last name");
	fancy_field("nickname");
	std::cout << "|" << std::endl;
	fancy_line();
	return (ALL_FINE);
}

int PhoneBook::print_contact(int id)
{
	std::string str;

	str = this->book[id].get_field(0);
	if (str.empty())
		return (ERROR);
	std::cout << "|" << std::setw(10) << id;
	for (size_t i = 0; i < 3; i++)
	{
		str = this->book[id].get_field(i);
		if (str.size() > 10)
		{
			str.resize(9);
			fancy_field(str + ".");
		}
		else
			fancy_field(str);
	}
	std::cout << "|" << std::endl;
	fancy_line();
	return (ALL_FINE);
}

int	PhoneBook::print_book(void)
{
	this->print_head();
	for (int i = 0; i < MAX_CONTACTS; i++)
		this->print_contact(i);
	std::cout << std::endl;
	return (ALL_FINE);
}

int PhoneBook::search(void)
{
	std::string	field[MAX_FIELDS] = {"First name:",
									"Second name:",
									"Nickname:",
									"Phone number:",
									"Secret:"};
	char		input;

	if (this->contacts_total <= 0)
	{
		std::cout << "Empty phonebook!\n" << std::endl;
		return (ERROR);
	}
	this->print_book();
	std::cout << "Enter an index:" << std::endl;
	std::cin >> input;
	input -= '0';
	if (input < 0 || input >= this->contacts_total)
	{
		std::cout << "Bad index" << std::endl;
		return (ERROR);
	}
	for (size_t i = 0; i < MAX_FIELDS; i++)
	{
		std::cout << std::left << std::setw(15) << field[i];
		std::cout << this->book[(int)input].get_field(i) << std::endl;
	}
	std::cout << std::endl;
	return (ALL_FINE);
}
