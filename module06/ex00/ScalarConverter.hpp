/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:46:22 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/30 13:50:40 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCLARACONVERTER_HPP
#define SCLARACONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <limits>
#include <cctype>

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
	public:
		static bool convert(const std::string& input);
};

#endif
