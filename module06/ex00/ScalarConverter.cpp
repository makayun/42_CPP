/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:49:25 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/30 14:00:18 by mmakagon         ###   ########.fr       */
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
	if (i == len)
		return (dot ? DOUBLE : INT);
	if (dot && i == len - 1 && input[i] == 'f')
		return (FLOAT);
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return (PSEUDO_FLOAT);
	if (input == "-inf" || input == "+inf" || input == "nan")
		return (PSEUDO_DOUBLE);
	return (CONVERT_ERR);
}

double convertToDouble(const std::string& input, const int& type) {
	double result = 0.0;
	double decimal_factor = 0.1;
	size_t i = 0;
	int digit;
	bool is_negative = false;
	bool decimal_found = false;

	if (type == CHAR)
		return (static_cast<double>(input[0]));

	if (input[0] == '-' || input[0] == '+')
		is_negative = (input[i++] == '-');
	for (; i < input.size(); ++i)
	{
		if (std::isdigit(input[i])) {
			digit = input[i] - '0';
			if (decimal_found) {
				result += digit * decimal_factor;
				decimal_factor *= 0.1;
			}
			else
				result = result * 10 + digit;
		}
		else if (input[i] == '.')
			decimal_found = true;
	}
	return (is_negative ? -result : result);
}


void printTypes(double d) {
	int		i = static_cast<int>(d);
	char	c = static_cast<char>(i);
	float	f = static_cast<float>(d);

	std::cout << "char: ";
	if (std::isprint(c))
		std::cout << "'" << c << "'";
	else
		std::cout << "Non displayable";

	std::cout	<< "\nint: " << i
				<< "\nfloat: " << std::fixed << std::setprecision(1) << f << "f"
				<< "\ndouble: " << std::fixed << std::setprecision(1) << d << std::endl;
}


void printPseudoLiteral(const std::string& input, int type) {
	if (type == PSEUDO_FLOAT)
		std::cout << "char: impossible\nint: impossible\nfloat: " << input << "\ndouble: " << input.substr(0, input.size() - 1) << std::endl;
	else
		std::cout << "char: impossible\nint: impossible\nfloat: " << input << "f\ndouble: " << input << std::endl;
}

bool ScalarConverter::convert(const std::string& input) {
	const int type = parseType(input);

	if (type == CONVERT_ERR) {
		std::cerr << "Error: Invalid input '" << input << "'" << std::endl;
		return false;
	}

	if (type == PSEUDO_DOUBLE || type == PSEUDO_FLOAT) {
		printPseudoLiteral(input, type);
		return true;
	}

	const double result = convertToDouble(input, type);
	printTypes(result);
	return true;
}
