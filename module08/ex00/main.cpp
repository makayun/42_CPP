#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>
#include "easyfind.hpp"

#define NEW_SECTION std::cout << "\n" << std::setw(50) << std::setfill('=') << "\n" << std::endl;

int main()
{
	NEW_SECTION

	try
	{
		std::vector<int> v;

		for (int i = 0; i < 5; i++)
			v.push_back(i);

		std::cout << "Looking for number 3 in vector v: " << *(easyfind(v, 3)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	NEW_SECTION

	try
	{
		std::list<int> l;

		for (int i = 0; i < 5; i++)
			l.push_back(i);

		std::cout << "Looking for number 7 in list l: " << *(easyfind(l, 7)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	NEW_SECTION
}
