/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:17:29 by mmakagon          #+#    #+#             */
/*   Updated: 2024/12/10 12:44:45 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


/* GLORIOUS ORTHODOX BULLS**T */

BitcoinExchange::BitcoinExchange() {
	std::ifstream data_file("data.csv");
	if (data_file.is_open()) {
		parseFile(data_file, &BitcoinExchange::addPair);
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

		for (std::map<Date, float>::const_iterator it = copy.data.begin(); it != copy.data.end(); ++it)
			data[it->first] = it->second;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}


/* PARSING */

Date		BitcoinExchange::parseDate(const std::string& line, const std::string& delimiter ) const {
	const size_t		del_pos = line.find(delimiter);
	if (del_pos == std::string::npos)
		throw (std::runtime_error("Error: bad input -> " + line));

	Date				ret;
	std::istringstream	date(line.substr(0, del_pos));
	std::string			temp;
	int i = 0;

	for ( ; i < 3 && getline(date, temp, '-'); ++i) {
		if (temp.empty())
			throw (std::runtime_error("Error: bad input -> " + line));
		ret.d[i] = std::atoi(temp.c_str());
	}
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

float		BitcoinExchange::parseValue(const std::string& line, const std::string& delimiter) const {
	const size_t		del_pos = line.find(delimiter);
	if (del_pos == std::string::npos)
		throw (std::runtime_error("Error: missing delimiter: " + line));

	const std::string temp = line.substr(del_pos + delimiter.length(), std::string::npos);
	if (temp.empty())
		throw(std::runtime_error("Error: bad input -> " + line));
	const double ret = std::atof(temp.c_str());

	if (ret < 0)
		throw (std::out_of_range("Error: not a positive number."));
	if (ret > INT_MAX)
		throw (std::out_of_range("Error: too large a number."));

	return(static_cast<float>(ret));
}

std::string	BitcoinExchange::parseDelimiter(const std::string& first_line) const {
	std::string ret;

	if (!first_line.empty() && first_line.find("date") != std::string::npos) {
		for (int i = 4; !std::isalnum(first_line[i]); ++i)
			ret.push_back(first_line[i]);
	}
	return (ret);
}

void		BitcoinExchange::parseFile(std::ifstream& in_file, void (BitcoinExchange::*funcPoint)(const Date&, const float&)) {
	std::string	line;
	std::getline(in_file, line);

	const std::string	delimiter = parseDelimiter(line);
	if (delimiter.empty())
		std::cerr << "Invalid data file's header!" << std::endl;

	else {
		Date		temp_date;
		float		temp_value;

		while (std::getline(in_file, line)) {
			if (line.empty()) continue;
			try {
				temp_date = parseDate(line, delimiter);
				temp_value = parseValue(line, delimiter);
				(this->*funcPoint)(temp_date, temp_value);
			}
			catch(const std::exception& e) {
				std::cerr << e.what() << std::endl;
			}
		}
	}
}


/* DATA FILE */

void BitcoinExchange::addPair(const Date& in_date, const float& in_value) {
	data[in_date] = in_value;
}


/* INPUT FILE */

void		BitcoinExchange::findAndPrint(const Date& in_date, const float& in_value) {
	if (in_value > 1000.0F)
		throw (std::out_of_range("Error: too large a number."));

	std::map<Date, float>::const_iterator it = data.upper_bound(in_date);
	if (it != data.begin()) {
		--it;
		if (it->first <= in_date) {
			std::cout << it->first << " => " << in_value << " = " << it->second * in_value << std::endl;
			return ;
		}
	}
	std::cerr << "Can't find this or closest lower date: " << in_date << std::endl;
}

void		BitcoinExchange::processInput(const std::string in_filename) {
	if (data.empty())
		std::cerr << "Invalid initial data!" << std::endl;

	else {
		std::ifstream input_file(in_filename.c_str());
		if (input_file.is_open()) {
			parseFile(input_file, &BitcoinExchange::findAndPrint);
			input_file.close();
		}
		else
			std::cerr << "Can't open input file!" << std::endl;
	}
}


/* DATE STRUCT */

Date::Date(){
	d[YEAR] = 0;
	d[MONTH] = 0;
	d[DAY] = 0;
}

Date::Date(const Date& copy) {
	this->d[YEAR] = copy.d[YEAR];
	this->d[MONTH] = copy.d[MONTH];
	this->d[DAY] = copy.d[DAY];
}

Date& Date::operator=(const Date& copy) {
	if (this != &copy) {
		this->d[YEAR] = copy.d[YEAR];
		this->d[MONTH] = copy.d[MONTH];
		this->d[DAY] = copy.d[DAY];
	}
	return (*this);
}

Date::~Date(){}

bool	Date::operator<(const Date& other) const {
	if (d[YEAR] != other.d[YEAR])
		return (d[YEAR] < other.d[YEAR]);
	if (d[MONTH] != other.d[MONTH])
		return (d[MONTH] < other.d[MONTH]);
	return (d[DAY] < other.d[DAY]);
}

bool	Date::operator==(const Date& other) const {
	return (d[YEAR] == other.d[YEAR] &&
			d[MONTH] == other.d[MONTH] &&
			d[DAY] == other.d[DAY]);
}

bool	Date::operator<=(const Date& other) const {
	return (*this < other || *this == other);
}

bool	Date::empty(void) const {
	return (!d[YEAR] && !d[MONTH] && !d[DAY]);
}

std::ostream &operator<<(std::ostream &out, Date const &in) {
	out << in.d[YEAR] << "-"
		<< std::setw(2) << std::setfill('0') << in.d[MONTH] << "-"
		<< std::setw(2) << std::setfill('0') << in.d[DAY];
	return out;
}

