/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:01:54 by mmakagon          #+#    #+#             */
/*   Updated: 2024/12/09 15:11:52 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <climits>
#include <map>

enum ymd {
	YEAR,
	MONTH,
	DAY
};

struct Date {
	int	d[3];
	Date();
	Date(const Date& copy);
	Date& operator=(const Date& copy);
	~Date();

	bool	operator<(const Date& other) const;
	bool	operator==(const Date& other) const;
	bool	operator<=(const Date& other) const;
	bool	empty(void) const;
};

std::ostream &operator<<(std::ostream &out, Date const &in);

class BitcoinExchange
{
	private:
		std::map<Date, float> data;

		std::string	parseDelimiter(const std::string& first_line);
		Date		parseDate(const std::string& line, const std::string& delimiter);
		float		parseValue(const std::string& line, const std::string& delimiter);
		bool		parseLine(const std::string& line);

		void		parseDataFile(std::ifstream& data_file);
		void		parseInputFile(std::ifstream& input_file);
		void		findAndPrint(const Date& in_date, const float& in_calue) const;

	public:
		BitcoinExchange();
		explicit			BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange&	operator=(const BitcoinExchange& copy);
		~BitcoinExchange();

		void		processInput(const std::string in_filename);
};


#endif
