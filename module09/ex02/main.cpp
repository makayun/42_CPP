/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:44:06 by mmakagon          #+#    #+#             */
/*   Updated: 2024/12/19 18:39:51 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <list>
#include <deque>
#include <climits>

// ./PmergeMe `shuf -i 1-100000 -n 5 | tr "\n" " "`

static int comparisons = 0;

#ifdef DEBUG
#define PRINT_VAR(x) std::cout << #x << ": " << x << std::endl
#else
#define PRINT_VAR(x)
#endif

std::ostream& operator<<( std::ostream& out, const std::deque<int>& in) {
	for (std::deque<int>::const_iterator it = in.begin(); it != in.end(); ++it)
		out << *it << " ";
	return (out);
}

void generateJacubsthal(std::deque<int>& jcbsthlArr, size_t size) {
	if (jcbsthlArr.empty()) {
		jcbsthlArr.push_back(0);
		size_t	current_jcb = 1;
		size_t	next_jcb = 3;
		size_t	i;

		while (jcbsthlArr.size() < size) {
			i = next_jcb;
			while (i > current_jcb)
				if (--i < size)
					jcbsthlArr.push_back(i);
			next_jcb += current_jcb * 2;
			current_jcb = next_jcb - current_jcb * 2;
		}
		PRINT_VAR(jcbsthlArr);
	}
	else
		std::cerr << "You probably are doing something wrong =)" << std::endl;
}

void pjDequeSort(std::deque<int>& a) {
	std::deque<int> b;

	for (size_t i = 0; a.size() > b.size(); ++i) {
		b.push_back(a[i]);
		a.erase(a.begin() + i);
		if (a.begin() + i != a.end() && ++comparisons && a[i] < b[i])
			std::swap(a[i], b[i]);
		PRINT_VAR(a);
		PRINT_VAR(b);
	}

	size_t j;

	for (size_t i = 1; i < a.size(); ++i) {
		j = i;
		while (j > 0 && a[j - 1] > a[i]) {
			++comparisons;
			--j;
		}
		if (j != i) {
			a.insert(a.begin() + j, a[i]);
			b.insert(b.begin() + j, b[i]);
			a.erase(a.begin() + i + 1);
			b.erase(b.begin() + i + 1);
		}
	}
	PRINT_VAR(a);
	PRINT_VAR(b);

	std::deque<int> jcbsthlArr;
	generateJacubsthal(jcbsthlArr, a.size());

	a.push_front(b[0]);
	PRINT_VAR(a);
	PRINT_VAR(b);
	size_t pos;
	for (size_t i = 1; i < jcbsthlArr.size(); ++i) {
		pos = (jcbsthlArr[i] + i) / 2;
		int& value_to_insert = b[jcbsthlArr[i]];
		if (value_to_insert < a[pos]) {
			++comparisons;
			while (--pos > 0 && ++comparisons && value_to_insert < a[pos]) {}
			a.insert(a.begin() + pos + 1, value_to_insert);
		}
		else {
			while (++pos < a.size() && ++comparisons && value_to_insert > a[pos]) {}
			a.insert(a.begin() + pos, value_to_insert);
		}
		PRINT_VAR(a);
		PRINT_VAR(b);
	}
}

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Try again" << std::endl;
		return (42);
	}

	std::deque<int>		d;
	std::list<int>		l;

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
			l.push_back(static_cast<int>(temp));
		}
	}
	std::cout << "Before: " << d << std::endl;
	pjDequeSort(d);
	std::cout << "After: " << d << std::endl;
	PRINT_VAR(comparisons);
}

