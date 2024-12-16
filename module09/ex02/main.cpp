/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:44:06 by mmakagon          #+#    #+#             */
/*   Updated: 2024/12/16 15:38:37 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <vector>
#include <list>

// ./PmergeMe `shuf -i 1-100000 -n 5 | tr "\n" " "`

/* PLAN:
Read arguments
Add elements to containers
Print them
Sort
Print the result
Print times
*/

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Try again" << std::endl;
		return (42);
	}

	std::vector<int>	v;
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
			v.push_back(temp);
			l.push_back(temp);
		}
	}

	std::cout << "Before:";
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << " " << v[i];
	std::cout << std::endl;
}

