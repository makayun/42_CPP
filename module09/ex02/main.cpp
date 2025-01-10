/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:34:50 by mmakagon          #+#    #+#             */
/*   Updated: 2025/01/10 22:34:23 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <climits>
#include "FJDeque.hpp"
#include "FJVector.hpp"

// ./PmergeMe `shuf -i 1-100 -n 21 | tr "\n" " "`
// ./PmergeMe `jot -r 21 1 100 | tr '\n' ' '`

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Try again" << std::endl;
		return (42);
	}

	std::deque<int>	d;
	std::deque<int> control_d;
	std::vector<int> v;
	std::vector<int> control_v;
	v.reserve(argc);
	control_v.reserve(argc);

	{
		std::istringstream	ss;
		long				temp;
		int					value;

		for (int i = 1; i < argc && argv[i]; ++i) {
			ss.clear();
			ss.str(argv[i]);
			if (!(ss >> temp) || temp < 1 || temp > INT_MAX) {
				std::cerr << "Error" << std::endl;
				return (42);
			}
			value = static_cast<int>(temp);
			d.push_back(value);
			control_d.push_back(value);
			v.emplace_back(value);
			control_v.emplace_back(value);
		}
	}

	assert(d == control_d);
	assert(v == control_v);

	std::cout << "Before: " << d << std::endl;
	FJDeque deq(d);
	measureTime(deq, &FJDeque::sort);
	std::cout << "After: " << d << std::endl;
	std::sort(control_d.begin(), control_d.end());
	assert(d == control_d);

	FJVector vec(v);
	measureTime(vec, &FJVector::sort);
	std::sort(control_v.begin(), control_v.end());
	assert (v == control_v);
}
