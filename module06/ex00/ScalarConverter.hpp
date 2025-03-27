/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:46:22 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/31 19:01:06 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCLARACONVERTER_HPP
#define SCLARACONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cmath>

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

class ScalarConverter
{
	private:
		ScalarConverter();

	public:
		static bool convert(const std::string& input);
};

template <typename TIn, typename TOut>
std::string numString(const TIn in, TOut out) {
	std::ostringstream	oss;

	if (in < std::numeric_limits<TOut>::min()
		|| in > std::numeric_limits<TOut>::max())
		return ("impossible");

	out = static_cast<TOut>(in);

	oss << std::fixed << std::setprecision(10) << out;

	std::string	ret = oss.str();
	size_t		dot = ret.find('.');

	if (dot != std::string::npos) {
		size_t i = ret.size() - 1;
		while (i > 0 && i > dot + 2 && ret[i] == '0')
			--i;
		ret.resize(i);
	}
	return (ret);
}

template <typename T>
std::string c_String(const T num) {
	if (num < 0 || num > 255)
		return ("impossible");

	char c = static_cast<char>(num);
	if (!std::isprint(c))
		return ("Non displayable");
	std::string ret;
	ret += c;
	return ("'" + ret + "'");
}

#endif
