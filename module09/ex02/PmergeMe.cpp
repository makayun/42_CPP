/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FJDeque.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:40:06 by mmakagon          #+#    #+#             */
/*   Updated: 2025/01/09 15:40:25 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool fillContainers (std::vector<int>& v, std::deque<int>& d, int argc, char** argv) {
	std::istringstream	ss;
	long				temp;

	for (int i = 1; i < argc && argv[i]; ++i) {
		ss.clear();
		ss.str(argv[i]);
		if (!(ss >> temp) || temp < 1 || temp > INT_MAX) {
			std::cerr << "Error" << std::endl;
			return (false);
		}
		int value = static_cast<int>(temp);
		d.push_back(value);
		v.emplace_back(value);
	}
	return (true);
}

