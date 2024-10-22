/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:46:17 by mmakagon          #+#    #+#             */
/*   Updated: 2024/10/21 19:07:58 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
		explicit			ScalarConverter(const ScalarConverter &copy);
		ScalarConverter&	operator=(const ScalarConverter &copy);
		~ScalarConverter();

	public:
		static void convert(const std::string& input);
};

#endif
