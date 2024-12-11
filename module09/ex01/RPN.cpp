/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:06:31 by mmakagon          #+#    #+#             */
/*   Updated: 2024/12/11 10:45:16 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


void	calculate(std::stack<int>& numbers, const std::string& str) {

	if (numbers.empty())
		throw std::runtime_error("Error, not enough operands!");
	long temp1 = static_cast<long>(numbers.top());
	numbers.pop();

	if (numbers.empty())
		throw std::runtime_error("Error, not enough operands!");
	long temp2 = static_cast<long>(numbers.top());
	numbers.pop();

	const int i = (str.size() == 1) * str[0];

	switch (i) {
		case '+':
			temp2 += temp1;
			break;
		case '-':
			temp2 -= temp1;
			break;
		case '*':
			temp2 *= temp1;
			break;
		case '/':
			if (temp1 == 0)
				throw std::runtime_error("Error, division by zero!");
			temp2 /= temp1;
			break;
		default:
			throw std::runtime_error("Error, invalid operator!");
	}
	if (temp2 > INT_MAX || temp2 < INT_MIN)
		throw std::out_of_range("Error, too big a number!");
	numbers.push(static_cast<int>(temp2));
}

int		rpn(const char* in_arg) {
	std::stack<int>		numbers;
	std::istringstream	input(in_arg);
	std::istringstream	to_int;
	std::string			str;
	long				l;

	try
	{
		while (input >> str) {
			to_int.clear();
			to_int.str(str);
			if (to_int >> l) {
				if (l > INT_MAX || l < INT_MIN)
					throw std::out_of_range("Error, too big a number!");
				numbers.push(static_cast<int>(l));
			}
			else
				calculate(numbers, str);
		}
		if (numbers.size() != 1)
			throw std::runtime_error("Error, not enough operators!");
		std::cout << numbers.top() << std::endl;
		return (0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
}
