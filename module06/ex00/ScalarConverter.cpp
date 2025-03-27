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

bool printChar(const char c) {
	std::cout	<< "char: '" << c << "'\n"
				<< "int: " << static_cast<int>(c) << "\n"
				<< std::fixed << std::setprecision(1)
				<< "float: " << static_cast<float>(c) << "f\n"
				<< "double: " << static_cast<double>(c)
				<< std::endl;
	return (true);
}

bool printInt(const int i) {
	std::cout	<< "char: " << c_String(i) << '\n'
				<< "int: " << i << '\n'
				<< std::fixed << std::setprecision(1)
				<< "float: " << static_cast<float>(i) << "f\n"
				<< "double: " << static_cast<double>(i)
				<< std::endl;
	return (true);
}

bool printFloat(const std::string& input, const float f) {
	int		i = 0;
	double	d = 0.0;

	std::cout	<< "char: " << c_String(f) << '\n'
				<< "int: " << numString(f, i) << '\n'
				<< "float: " << input << '\n'
				<< "double: " << numString(f, d)
				<< std::endl;
	return (true);
}

bool printDouble(const std::string& input, const double d) {
	int		i = 0;
	float	f = 0.0f;
	std::string tail = "";

	if (input.find('.') == std::string::npos)
		tail = ".0";

	std::cout	<< "char: " << c_String(d) << '\n'
				<< "int: " << numString(d, i) << '\n'
				<< "float: " << numString(d, f) << "f\n"
				<< "double: " << input << tail
				<< std::endl;
	return (true);
}

bool printErr() {
	std::cerr << "Wrong input!" << std::endl;
	return (false);
}

bool ScalarConverter::convert(const std::string& input) {
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return (printPseudo(input, input.substr(0, input.size() - 1)));
	if (input == "-inf" || input == "+inf" || input == "nan")
		return (printPseudo(input + "f", input));

	std::stringstream	ss(input);

	{
		int	i;

		if (ss >> i && ss.eof())
			return (printInt(i));
	}

	{
		std::string	tail;
		float		f;

		ss.clear();
		ss.str(input);
		if (ss >> f && ss >> tail && tail == "f")
			return (printFloat(input, f));
	}

	{
		double	d;

		ss.clear();
		ss.str(input);
		if (ss >> d && ss.eof())
			return (printDouble(input, d));
	}

	if (input.size() == 1 && std::isprint(input[0]))
		return (printChar(input[0]));

	return (printErr());
}
