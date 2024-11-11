/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:44:41 by mmakagon          #+#    #+#             */
/*   Updated: 2024/11/09 03:55:21 by mmakagon         ###   ########.fr       */
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

	return 0;
}
