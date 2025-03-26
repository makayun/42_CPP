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

bool printPseudo(const std::string& f, const std::string& d) {
	std::cout	<< "char: impossible\n"
				<< "int: impossible\n"
				<< "float: " << f << "\n"
				<< "double: " << d
				<< std::endl;
	return (true);
}

bool printNum(double d) {
	std::string character = "Non displayable";
	std::string integer = "impossible";
	std::string floating = "impossible";
	std::ostringstream	oss;

	if (d >= std::numeric_limits<float>::min() && d <= std::numeric_limits<float>::max()) {
		oss << std::fixed << std::setprecision(1) << static_cast<float>(d);
		floating = oss.str();
	}

	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max()) {
		int i = static_cast<int>(d);
		oss.str("");
		oss << i;
		integer = oss.str();
		if (std::isprint(i))
			character = static_cast<char>(i);
	}

	std::cout	<< "char: " << character << "\n"
				<< "int: " << integer << "\n"
				<< "float: " << floating << "f\n"
				<< "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	return (true);
}

bool printChar(const char c) {
	std::cout	<< "char: " << c << "\n"
				<< "int: " << static_cast<int>(c) << "\n"
				<< "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f\n"
				<< "double: " << static_cast<double>(c)
				<< std::endl;
	return (true);
}

bool printErr() {
	std::cerr << "Wrong input!" << std::endl;
	return (false);
}

bool ScalarConverter::convert2(const std::string& input) {
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return (printPseudo(input, input.substr(0, input.size() - 1)));
	if (input == "-inf" || input == "+inf" || input == "nan")
		return (printPseudo(input + "f", input));

	std::stringstream	ss(input);
	double				d;

	if (ss >> d && ss.eof())
			return (printNum(d));
	else if (input.size() == 1)
		return (printChar(input[0]));
	else
		return (printErr());
}
