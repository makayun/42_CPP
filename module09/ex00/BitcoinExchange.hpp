/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:01:54 by mmakagon          #+#    #+#             */
/*   Updated: 2024/12/09 13:24:11 by mmakagon         ###   ########.fr       */
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

typedef struct s_date {
	int	d[3];

	bool	operator<(const s_date& other) const {
		if (d[YEAR] != other.d[YEAR])
			return (d[YEAR] < other.d[YEAR]);
		if (d[MONTH] != other.d[MONTH])
			return (d[MONTH] < other.d[MONTH]);
		return (d[DAY] < other.d[DAY]);
	}

	bool empty(void) {
		return (!d[YEAR] && !d[MONTH] && !d[DAY]);
	}
} t_date;

std::ostream &operator<<( std::ostream &out, t_date const &in );

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

	public:
		BitcoinExchange();
		explicit BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& copy);
		~BitcoinExchange();

		void		processInput(const std::string in_filename);
};


#endif
