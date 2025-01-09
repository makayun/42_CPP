/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:34:50 by mmakagon          #+#    #+#             */
/*   Updated: 2025/01/09 18:18:15 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ./PmergeMe `shuf -i 1-100 -n 21 | tr "\n" " "`
// ./PmergeMe `jot -r 21 1 100 | tr '\n' ' '`

void findUnsortedElement(const std::deque<int>& d) {
	for (size_t i = 1; i < d.size(); ++i) {
		if (d.at(i) < d.at(i - 1))
			std::cout 	<< "\nIndex: " << i
						<< "\nNumber: " << d.at(i)
						<< "\nPrevious: " << d.at(i - 1)
						<< std::endl;
	}
}

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Try again" << std::endl;
		return (42);
	}

	std::deque<int>	d;
	std::deque<int> control_d;

	{
		std::istringstream	ss;
		long				temp;

		for (int i = 1; i < argc && argv[i]; ++i) {
			ss.clear();
			ss.str(argv[i]);
			if (!(ss >> temp) || temp < 1 || temp > INT_MAX) {
				std::cerr << "Error" << std::endl;
				return (42);
			}
			d.push_back(static_cast<int>(temp));
			control_d.push_back(static_cast<int>(temp));
		}
	}

	assert(d == control_d);

	std::cout << "Before: " << d << std::endl;
	FJDeque sorter(d);
	sorter.sort();
	std::cout << "After: " << d << std::endl;
	std::sort(control_d.begin(), control_d.end());
	assert(d == control_d);
}
