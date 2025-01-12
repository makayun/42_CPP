/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FJDeque.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:07:53 by mmakagon          #+#    #+#             */
/*   Updated: 2025/01/09 15:36:12 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <sys/time.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <climits>
#include <deque>
#include <vector>

#ifdef DEBUG
#define PRINT_VAR(x) std::cout << #x << ": " << x << std::endl
#define SECTION(x) std::cout << x << std::endl
#else
#define PRINT_VAR(x)
#define SECTION(x)
#endif

bool fillContainers (std::vector<int>& v, std::deque<int>& d, int argc, char** argv);

template<typename T>
void generateJacubsthal(T& jcbsthl, size_t size) {
	jcbsthl.push_back(0);
	size_t	current_jcb = 1;
	size_t	next_jcb = 3;

	while (jcbsthl.size() < size) {
		size_t i = next_jcb;
		while (i > current_jcb)
			if (--i < size)
				jcbsthl.push_back(i);
		next_jcb += current_jcb * 2;
		current_jcb = next_jcb - current_jcb * 2;
	}
}

template<typename ClassType>
void printResults(ClassType& obj, const double elapsed, const std::string& containerType) {
	std::cout << "Time to process a range of "
			  << obj.getSize() << " elements with "
			  << containerType << " : "
			  << std::fixed << elapsed << " s"
			  << std::endl;
}

template<typename ClassType>
double measureTime(ClassType& obj, void(ClassType::*funptr)(void)) {
	std::clock_t	start, end;
	double			elapsed;

	start = std::clock();
	(obj.*funptr)();
	end = std::clock();

	elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	return (elapsed);
}

#endif
