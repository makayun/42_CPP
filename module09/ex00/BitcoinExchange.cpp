/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:17:29 by mmakagon          #+#    #+#             */
/*   Updated: 2024/12/09 13:27:33 by mmakagon         ###   ########.fr       */
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
	const size_t		del_pos = line.find(delimiter);
	if (del_pos == std::string::npos)
		throw (std::runtime_error("Error: bad input -> " + line));

	t_date				ret;
	std::istringstream	date(line.substr(0, del_pos));
	std::string			temp;
	int i = 0;

	for ( ; i < 3 && getline(date, temp, '-'); ++i)
		ret.d[i] = std::atoi(temp.c_str());
	if (i < 3)
		throw (std::runtime_error("Error: bad input -> " + line));

	if (ret.d[YEAR] < 1 || ret.d[MONTH] < 1 || ret.d[MONTH] > 12)
		throw (std::out_of_range("Error: bad input -> " + line));

	int days_in_month;
	switch (ret.d[MONTH]){
		case 2:
			days_in_month = (ret.d[YEAR] % 4 == 0 && (ret.d[YEAR] % 100 != 0 || ret.d[YEAR] % 400 == 0)) ? 29 : 28;
			break;
		case 4: case 6: case 9: case 11:
			days_in_month = 30;
			break;
		default:
			days_in_month = 31;
			break;
	}

	if (ret.d[DAY] < 1 || ret.d[DAY] > days_in_month)
		throw (std::out_of_range("Error: bad input -> " + line));
	return (ret);
}

float	BitcoinExchange::parseValue(const std::string& line, const std::string& delimiter) {
	const size_t		del_pos = line.find(delimiter);
	if (del_pos == std::string::npos)
		throw (std::runtime_error("Error: missing delimiter: " + line));

	const std::string temp = line.substr(del_pos + delimiter.length(), std::string::npos);
	const double ret = std::atof(temp.c_str());

	if (ret < 0)
		throw (std::out_of_range("Error: not a positive number."));
	if (ret > INT_MAX)
		throw (std::out_of_range("Error: too large a number."));

	return(static_cast<float>(ret));
}

std::string	BitcoinExchange::parseDelimiter(const std::string& first_line) {
	std::string ret;

	if (!first_line.empty() && first_line.find("date") != std::string::npos) {
		for (int i = 4; !std::isalnum(first_line[i]); ++i)
			ret.push_back(first_line[i]);
	}
	return (ret);
}

void	BitcoinExchange::parseDataFile(std::ifstream& data_file) {
	std::string	line;
	std::getline(data_file, line);

	const std::string	delimiter = parseDelimiter(line);
	if (delimiter.empty())
		std::cerr << "Invalid data file's header!" << std::endl;

	else {
		t_date		temp_date;
		float		temp_value;
		while (std::getline(data_file, line)) {
			if (line.empty()) continue;
			try {
				temp_date = parseDate(line, delimiter);
				temp_value = parseValue(line, delimiter);
			}
			catch(const std::exception& e) {
				std::cerr << e.what() << std::endl;
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


std::ostream &operator<<(std::ostream &out, t_date const &in) {
	out << in.d[YEAR] << "-"
		<< std::setw(2) << std::setfill('0') << in.d[MONTH] << "-"
		<< std::setw(2) << std::setfill('0') << in.d[DAY];
	return out;
}

