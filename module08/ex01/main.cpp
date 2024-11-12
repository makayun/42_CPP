/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:44:41 by mmakagon          #+#    #+#             */
/*   Updated: 2024/11/11 11:51:38 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Span.hpp"
#include "measureTime.tpp"

#define NEW_SECTION std::cout << "\n" << std::setw(50) << std::setfill('=') << "\n" << std::endl;

void testSpans(const Span& sp, const int& N) {
	std::cout << "\nShortestSpan on " << N << " elements:" << std::endl;
	measureTime(sp, &Span::shortestSpan);
	std::cout << "\nShortestSpan2 on " << N << " elements:" << std::endl;
	measureTime(sp, &Span::shortestSpan2);
	std::cout << "\nLongestSpan on " << N << " elements:" << std::endl;
	measureTime(sp, &Span::longestSpan);
}

int main()
{
	int N;

	{
		N = 5;
		Span tiny = Span(N);

		tiny.addNumber(6);
		tiny.addNumber(3);
		tiny.addNumber(17);
		tiny.addNumber(9);
		tiny.addNumber(11);

		testSpans(tiny, N);

		tiny.clear();
		tiny.fillRandom(N);
		for (int i = 0; i < N; i++)
			std::cout << tiny[i] << std::endl;
	}

	NEW_SECTION

	{
		Span big(100000); // hundred thousand

		N = 10000; // ten thousand
		std::cout << "FillRandom with " << N << " elements:" << std::endl;
		measureTime(big, &Span::fillRandom, N);
		testSpans(big, N);

		NEW_SECTION

		N = 100000; // hundred thousand
		big.clear();
		std::cout << "FillRandom with " << N << " elements:" << std::endl;
		measureTime(big, &Span::fillRandom, N);
		testSpans(big, N);
	}

	NEW_SECTION

	// {
	// 	N = 1000000; // one million
	// 	std::vector<int> v(N);
	// 	std::random_device rd;
	// 	std::mt19937 gen(rd());
	// 	std::uniform_int_distribution<int> dist(INT_MIN, INT_MAX);
	// }

	return 0;
}
