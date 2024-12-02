/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:49:25 by mmakagon          #+#    #+#             */
/*   Updated: 2024/11/18 11:38:27 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int parseType(const std::string& input) {
	const ssize_t len = input.size();
	ssize_t i = 0;
	bool dot = false;

	if (len == 0)
		return (CONVERT_ERR);
	if (len == 1 && !std::isdigit(input[0]) && std::isprint(input[0]))
		return (CHAR);
	if (input[0] == '-' || input[0] == '+')
		i++;
	while (i < len && std::isdigit(input[i])) {
		i++;
		if (i < len && input[i] == '.') {
			if (dot)
				return (CONVERT_ERR);
			dot = true;
			i++;
		}
	}
	if (i == len && std::isdigit(input[len - 1]))
		return (dot ? DOUBLE : INT);
	if (dot && i == len - 1 && input[i] == 'f')
		return (FLOAT);
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return (PSEUDO_FLOAT);
	if (input == "-inf" || input == "+inf" || input == "nan")
		return (PSEUDO_DOUBLE);
	return (CONVERT_ERR);
}

bool printPseudoLiteral(const std::string& input, const int& type) {
	if (type == PSEUDO_FLOAT)
		std::cout << "char: impossible\nint: impossible\nfloat: " << input << "\ndouble: " << input.substr(0, input.size() - 1) << std::endl;
	else
		std::cout << "char: impossible\nint: impossible\nfloat: " << input << "f\ndouble: " << input << std::endl;
	return (true);
}

bool displayConversions(char value) {
	std::cout << "char: ";
	if (std::isprint(value))
		std::cout << "'" << value << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
	return (true);
}

bool displayConversions(long value) {
	std::cout << "char: ";
	if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max() && std::isprint(static_cast<char>(value)))
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
	return (true);
}

bool displayConversions(float value) {
	std::cout << "char: ";
	if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max() && std::isprint(static_cast<char>(value)))
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: ";
	if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
		std::cout << static_cast<int>(value) << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "float: "  << value << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
	return (true);
}

bool displayConversions(double value) {
	std::cout << "char: ";
	if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max() && std::isprint(static_cast<char>(value)))
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: ";
	if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
		std::cout << static_cast<int>(value) << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "float: ";
	if (value >= -std::numeric_limits<float>::max() && value <= std::numeric_limits<float>::max())
		std::cout << static_cast<float>(value) << "f" << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "double: " << value << std::endl;
	return (true);
}


bool ScalarConverter::convert(const std::string& input) {
	char		c;
	long		i;
	float		f;
	double		d;
	const int	type = parseType(input);

	switch (type)
	{
		case CONVERT_ERR:
			std::cerr << "Error: Invalid input '" << input << "'" << std::endl;
			return false;
		case CHAR:
			c = input[0];
			return (displayConversions(c));
		case INT:
			i = std::strtol(input.c_str(), NULL, 10);
			return (displayConversions(i));
		case FLOAT:
			f = std::strtof(input.c_str(), NULL);
			return (displayConversions(f));
		case DOUBLE:
			d = std::strtod(input.c_str(), NULL);
			return (displayConversions(d));
		case PSEUDO_FLOAT: case PSEUDO_DOUBLE:
			return (printPseudoLiteral(input, type));
		default:
			return (false);
	}
}
