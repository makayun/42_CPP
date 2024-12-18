/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:44:06 by mmakagon          #+#    #+#             */
/*   Updated: 2024/12/18 13:11:29 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <list>
#include <deque>

// ./PmergeMe `shuf -i 1-100000 -n 5 | tr "\n" " "`

/* PLAN:
Read arguments
Add elements to containers
Print them
Sort
Print the result
Print times
*/

#define PRINT_VAR(x) std::cout << #x << ": " << x << std::endl

std::ostream& operator<<( std::ostream& out, const std::deque<int>& in)
{
	for (std::deque<int>::const_iterator it = in.begin(); it != in.end(); ++it)
		out << *it << " ";
	return (out);
}

void pjDequeSort(std::deque<int>& a) {
	std::deque<int> b;
	size_t i = 0;

	while (i <= a.size() / 2) {
		b.push_back(a[i]);
		a.erase(a.begin() + i);
		if (a[i] < b[i])
			std::swap(a[i], b[i]);
		PRINT_VAR(a);
		PRINT_VAR(b);
		++i;
	}

	i = 1;
	size_t j;
	int temp_a;
	int temp_b;
	int index;
	while (i < b.size()) {
		temp_a = a[i];
		temp_b = b[i];
		a.erase(a.begin() + i);
		b.erase(b.begin() + i);
		j = i - 1;
		for ( ; j > 0; --j)
			if (a[j] >= temp_a)
				index = j;
		a.insert(a.begin() + index, temp_a);
		b.insert(b.begin() + index, temp_b);
		++i;
	}
	PRINT_VAR(a);
	PRINT_VAR(b);

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
			if (!(ss >> temp) || temp < 1) {
				std::cerr << "Error" << std::endl;
				return (42);
			}
			d.push_back(temp);
			l.push_back(temp);
		}
	}
	PRINT_VAR(d);
	pjDequeSort(d);
}

