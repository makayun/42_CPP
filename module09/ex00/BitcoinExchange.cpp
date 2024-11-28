/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:17:29 by mmakagon          #+#    #+#             */
/*   Updated: 2024/11/28 12:59:17 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string in_filename) {
	std::ifstream data_file("data.csv");
	if (!data_file.is_open())
		throw std::runtime_error("Can't open the data file!\n");

	std::ifstream input_file(in_filename.c_str());
	if (!input_file.is_open())
		throw std::runtime_error("Can't open the input file!\n");

	parseData(data_file);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
	*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy) {
	if (this != &copy) {
		data.clear();

		for (std::map<t_date, float>::const_iterator it = copy.data.begin(); it != copy.data.end(); ++it) {
			data[it->first] = it->second;
		}
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}
