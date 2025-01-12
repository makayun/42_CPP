/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:34:50 by mmakagon          #+#    #+#             */
/*   Updated: 2025/01/12 01:57:27 by mmakagon         ###   ########.fr       */
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

	std::deque<int>	d;
	std::vector<int> v;
	v.reserve(argc - 1);

	if (fillContainers(v, d, argc, argv) == false)
		return (42);

	std::deque<int>	control_d(d);
	std::vector<int> control_v(v);

	std::cout << "Before: " << v << std::endl;

	FJDeque deq(d);
	const double deq_time = measureTime(deq, &FJDeque::sort);

	FJVector vec(v);
	const double vec_time = measureTime(vec, &FJVector::sort);

	std::cout << "After: " << v << std::endl;

	printResults(vec, vec_time, "std::vector");
	printResults(deq, deq_time, "std::deque");

	std::sort(control_d.begin(), control_d.end());
	std::sort(control_v.begin(), control_v.end());
	assert(d == control_d);
	assert (v == control_v);
}
