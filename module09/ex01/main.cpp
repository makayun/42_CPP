/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:16:16 by mmakagon          #+#    #+#             */
/*   Updated: 2024/12/10 14:30:21 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <stack>
#include <climits>

void calculate(std::stack<int>& numbers, std::string& str) {
	if (numbers.empty())
		throw std::runtime_error("Error");
	long temp1 = static_cast<long>(numbers.top());
	numbers.pop();
	if (numbers.empty())
		throw std::runtime_error("Error");
	long temp2 = static_cast<long>(numbers.top());
	numbers.pop();


	int i = 0;
	std::string operations[4] = {"+", "-", "*", "/"};
	while(i < 4) {
		if (str == operations[i])
			break;
		++i;
	}

	std::cout << operations[i] << std::endl;

	switch (i) {
		case 0:
			temp2 += temp1;
			break;
		case 1:
			temp2 -= temp1;
			break;
		case 2:
			temp2 *= temp1;
			break;
		case 3:
			if (temp1 == 0)
				throw std::runtime_error("Error");
			temp2 /= temp1;
			break;
		default:
			throw std::runtime_error("Error");
	}
	if (temp2 > INT_MAX || temp2 < INT_MIN)
		throw std::out_of_range("Error");
	numbers.push(static_cast<int>(temp2));
}


int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Try again" << std::endl;
		return(42);
	}

	std::istringstream ss(argv[1]);
	int i;
	std::string str;
	std::stack<int> numbers;



	try
	{
		while (ss >> std::ws) {
			if (!numbers.empty())
				std::cout << "top: " << numbers.top() << std::endl;
			if (ss >> i) {
				std::cout << "int: " << i << std::endl;
				numbers.push(i);
			}
			else if (ss >> str)
				calculate(numbers, str);
			else
				break;
			// else {
			// 	ss.clear();
			// 	if (ss >> str) {
			// 		std::cout << "str: " << str << std::endl;
			// 		calculate(numbers, str);
			// 	}
			// 	else
			// 		break;
			// }
		}
		std::cout << numbers.top() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


}
