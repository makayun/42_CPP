/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:17:29 by mmakagon          #+#    #+#             */
/*   Updated: 2024/11/28 15:49:33 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::ifstream data_file("data.csv");
	if (data_file.is_open()) {
		parseData(data_file);
		data_file.close();
	}
	else
		std::cerr << "Caan't open the data file!" << std::endl;
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

void		BitcoinExchange::parseData(std::ifstream& data_file) {
	std::string line = std::getline(data_file);
	if (line.find("data") == line.end())
}


void		BitcoinExchange::processInput(const std::string in_filename) {
	if (data.empty())
		std::cerr << "Invalid data!" << std::endl;

	else {
		std::ifstream input_file(in_filename.c_str());
		if (input_file.is_open()) {
			parseInput(input_file);
			input_file.close();
		}
		else
			std::cerr << "Can't open input file!" << std::endl;
	}
}

void		BitcoinExchange::printDate(const t_date& to_print) const {
	std::cout << to_print.year << "-" << to_print.month << "-" << to_print.day;
}
