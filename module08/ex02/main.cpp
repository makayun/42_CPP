/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:52:22 by mmakagon          #+#    #+#             */
/*   Updated: 2024/11/14 15:58:03 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "MutantStack.hpp"

#define NEW_SECTION std::cout << "\n" << std::setw(50) << std::setfill('=') << "\n" << std::endl;
#define PRINT_VAR(x) std::cout << #x << ": " << x << std::endl;

int main()
{
	NEW_SECTION

	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		PRINT_VAR(mstack.top())
		mstack.pop();
		PRINT_VAR(mstack.size())
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		PRINT_VAR(mstack.size())
		std::stack<int> temp_copy(mstack);
		PRINT_VAR(temp_copy.size())
	}

	NEW_SECTION

	{
		MutantStack<char> mstack1;
		mstack1.push('a');
		mstack1.push('b');
		mstack1.push('c');

		MutantStack<char> mstack2(mstack1);
		std::cout << "Size of mstack2: " << mstack2.size() << std::endl;
		while (!mstack2.empty()) {
			PRINT_VAR(mstack2.top())
			mstack2.pop();
		}
	}

	NEW_SECTION

	{
		MutantStack<std::string> mstack3;
		mstack3.push("abc");
		mstack3.push("def");
		mstack3.push("ghi");

		PRINT_VAR(mstack3.size())
		MutantStack<std::string>::iterator it = mstack3.begin();
		while (it != mstack3.end())
			PRINT_VAR(*it++)
		std::cout << std::endl;
	}

	return 0;
}
