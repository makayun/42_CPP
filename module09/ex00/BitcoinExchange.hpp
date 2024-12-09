/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:01:54 by mmakagon          #+#    #+#             */
/*   Updated: 2024/12/02 19:17:26 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

typedef struct s_date {
	int year;
	int month;
	int day;

	bool operator<(const s_date& other) const {
		if (year != other.year)
			return year < other.year;
		if (month != other.month)
			return month < other.month;
		return day < other.day;
	}

	bool empty(void) {
		return (!year && !month && !day);
	}
} t_date;

class BitcoinExchange
{
	private:
		std::map<t_date, float> data;

		std::string	parseDelimiter(const std::string& first_line);
		t_date		parseDate(const std::string& line, const std::string& delimiter);
		float		parseValue(const std::string& line, const std::string& delimiter);
		bool		parseLine(const std::string& line);

		void		parseDataFile(std::ifstream& data_file);
		void		parseInputFile(std::ifstream& input_file);

		void		printDate(const t_date& to_print) const;

	public:
		BitcoinExchange();
		explicit BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& copy);
		~BitcoinExchange();

		void		processInput(const std::string in_filename);
};


#endif
