/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:17:29 by mmakagon          #+#    #+#             */
/*   Updated: 2024/12/02 19:19:10 by mmakagon         ###   ########.fr       */
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
		std::cerr << "Can't open the data file!" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
	*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy) {
	if (this != &copy) {
		data.clear();

		for (std::map<t_date, float>::const_iterator it = copy.data.begin(); it != copy.data.end(); ++it)
			data[it->first] = it->second;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

t_date	BitcoinExchange::parseDate(const std::string& line, const std::string& delimiter ) {
	t_date				ret;
	const size_t		del_pos = line.find(delimiter);

	


}

std::string	BitcoinExchange::parseDelimiter(const std::string& first_line) {
	std::string ret;

	if (!first_line.empty() && first_line.find("date") != std::string::npos) {
		for (int i = 4; !std::isalnum(first_line[i]); ++i)
			ret.push_back(first_line[i]);
	}
	return (0);
}

void	BitcoinExchange::parseDataFile(std::ifstream& data_file) {
	t_date		temp_date;
	float		temp_value;
	std::string	line;
	std::getline(data_file, line);

	const std::string	delimiter = parseDelimiter(line);
	if (delimiter.empty())
		std::cerr << "Invalid data file's header!" << std::endl;

	else {
		while (std::getline(data_file, line)) {
			if (line.empty()) continue;
			try {
				temp_date = parseDate(line, delimiter);
				temp_value = parseValue(line, delimiter);
			}
			catch(const std::exception& e) {
				std::cerr << e.what() << '\n';
				data.clear();
				return ;
			}
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
