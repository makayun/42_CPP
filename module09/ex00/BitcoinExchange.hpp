/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:01:54 by mmakagon          #+#    #+#             */
/*   Updated: 2024/11/28 12:58:29 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
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
} t_date;

class BitcoinExchange
{
	private:
		std::map<t_date, float> data;

		std::string	parseSeparator(const std::string& first_line);
		t_date		parseDate(const std::string& line, const std::string& separator);
		float		parseValue(const std::string& line, const std::string& separator);
		bool		parseLine(const std::string& line);

		void		parseData(std::ifstream& data_file);

		void		printDate(const t_date& date);

	public:
		BitcoinExchange(); // do nothing or print some error
		explicit BitcoinExchange(const std::string in_filename); // open data.csv
		explicit BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& copy);
		~BitcoinExchange();
};


#endif
