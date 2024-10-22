/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:29:20 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/22 16:12:02 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

enum e_literals_types {
	CONVERT_ERR = -1,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	TYPE_MAX
};

int parse(const std::string& input) {
	const ssize_t	len = input.size();
	int				i = 0;
	bool			dot = false;

	if (len == 1 && !std::isdigit(input[0]) && std::isprint(input[0]))
		return (CHAR);
	if (input[0] == '-' || input[0] == '+')
		i++;
	while (std::isdigit(input[i])) {
		i++;
		if (input[i] == '.') {
			dot = true;
			i++;
		}
	}
	if (i == len) {
		if (dot)
			return (DOUBLE);
		return (INT);
	}
	if (dot && i == len - 1 && input[i] == 'f')
		return (FLOAT);
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return (FLOAT);

	return (CONVERT_ERR);
}

bool convert(const std::string& input) {
	std::cout << parse(input) << std::endl;

	return (true);
}

int main() {
	const std::string input[TYPE_MAX] = {"A", "-10", "0f", "-3.0"};

	for (int i = 0; i < TYPE_MAX; i++) {
		convert(input[i]);
	}
}
