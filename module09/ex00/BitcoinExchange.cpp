/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:17:29 by mmakagon          #+#    #+#             */
/*   Updated: 2024/12/02 12:54:03 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::ifstream data_file("data.csv");
	if (data_file.is_open()) {
		parseDataFile(data_file);
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



char	BitcoinExchange::parseDelimiter(const std::string& first_line) {
	if (!first_line.empty() && first_line.find("date") != std::string::npos) {
		if (first_line.find('|') != std::string::npos)
			return ('|');
		if (first_line.find(',') != std::string::npos)
			return (',');
	}
	return (0);
}

void	BitcoinExchange::parseDataFile(std::ifstream& data_file) {
	std::string key, value;
	t_date		temp_date;
	float		temp_value;
	std::string	line;
	std::getline(data_file, line);

	const char	delimiter = parseDelimiter(line);
	if (!delimiter)
		std::cerr << "Invalid data file's header!" << std::endl;

	else {
		while (std::getline(data_file, line)) {
			if (line.empty()) continue;
			std::istringstream lineStream(line);
			std::getline(lineStream, key, delimiter);
			temp_date = parseDate(key);
			std::getline(lineStream, value);
			temp_value = parseValue(value);
			if (temp_date.empty() || temp_value < 0 || temp_value > 1000) {
				data.clear();
				return ;
			}
			else
				data[temp_date] = temp_value;
		}
	}
}


void	BitcoinExchange::processInput(const std::string in_filename) {
	if (data.empty())
		std::cerr << "Invalid initial data!" << std::endl;

	else {
		std::ifstream input_file(in_filename.c_str());
		if (input_file.is_open()) {
			parseInputFile(input_file);
			input_file.close();
		}
		else
			std::cerr << "Can't open input file!" << std::endl;
	}
}

void	BitcoinExchange::printDate(const t_date& to_print) const {
	std::cout << to_print.year << "-" << to_print.month << "-" << to_print.day;
}
