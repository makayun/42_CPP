/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:29:20 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/25 13:10:22 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

enum e_types {
	CONVERT_ERR = -1,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO_FLOAT,
	PSEUDO_DOUBLE,
	TYPE_MAX
};

int parse_type(const std::string& input) {
	const ssize_t	len = input.size();
	ssize_t			i = 0;
	bool			dot = false;

	if (len == 0)
		return (CONVERT_ERR);
	if (len == 1 && !std::isdigit(input[0]) && std::isprint(input[0]))
		return (CHAR);
	if (input[0] == '-' || input[0] == '+')
		i++;
	while (std::isdigit(input[i]))
		if (input[++i] == '.')
			dot = input[++i];
	if (i == len)
		return (dot ? DOUBLE : INT);
	if (dot && i == len - 1 && input[i] == 'f')
		return (FLOAT);
	if ((i == 1 && input.substr(i) == "inff") || input == "nanf")
		return (PSEUDO_FLOAT);
	if ((i == 1 && input.substr(i) == "inf") || input == "nan")
		return (PSEUDO_DOUBLE);
	return (CONVERT_ERR);
}

bool convert(const std::string& input) {
	int type = parse_type(input);
	std::cout << type << std::endl;
	if (type == CONVERT_ERR)
		return (false);

	return (true);
}

int main() {
	const std::string in_chars[4] = {"-", "a", "±", ""};

	for (int i = 0; i < TYPE_MAX; i++) {
		convert(input[i]);
	}
}
