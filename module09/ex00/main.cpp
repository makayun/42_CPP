/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:32:03 by mmakagon          #+#    #+#             */
/*   Updated: 2024/12/02 15:06:06 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Use: " << argv[0] << " <input_file>" << std::endl;
		return (42);
	}


	return 0;
}
