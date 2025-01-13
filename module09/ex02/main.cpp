/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:34:50 by mmakagon          #+#    #+#             */
/*   Updated: 2025/01/13 09:41:55 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FJDeque.hpp"
#include "FJVector.hpp"
#include "PmergeMe.hpp"

// ./PmergeMe `shuf -i 1-100 -n 21 | tr "\n" " "`
// ./PmergeMe `jot -r 21 1 100 | tr '\n' ' '`

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Try again" << std::endl;
		return (42);
	}

	std::vector<int> v;
	std::deque<int>	d;
	v.reserve(argc - 1);

	if (fillContainers(v, d, argc, argv) == false)
		return (42);

	std::vector<int> control_v(v);
	std::deque<int>	control_d(d);

	std::cout << "Before: " << v << std::endl;

	FJVector vec(v);
	const double vec_time = measureTime(vec, &FJVector::sort);

	FJDeque deq(d);
	const double deq_time = measureTime(deq, &FJDeque::sort);

	std::cout << "After: " << v << std::endl;

	printResults(vec, vec_time, "std::vector");
	printResults(deq, deq_time, "std::deque");

	std::sort(control_v.begin(), control_v.end());
	std::sort(control_d.begin(), control_d.end());
	assert (v == control_v);
	assert(d == control_d);
}
