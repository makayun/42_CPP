/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:44:56 by mmakagon          #+#    #+#             */
/*   Updated: 2024/11/12 15:04:54 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <limits>

class Span
{
	private:
		std::multiset<int>	_elements;
		size_t				_max_size;

	public:
		Span();
		explicit		Span(const unsigned int N);
		Span(const Span& copy);
		Span&			operator=(const Span& copy);
		~Span();

		const int&		operator[](const int& n) const;

		void			addNumber(const int& n);
		void			fillRandom(const int& number_of_elements);
		void			clear(void);


		template<typename Container>
		void addFromOther(const Container& in_cont) {
			if (_elements.size() + std::distance(in_cont.begin(), in_cont.end()) > _max_size)
				throw std::logic_error("The new size exceeds the upper limit");

			_elements.insert(in_cont.begin(), in_cont.end());
		}

		// template<typename Iterator>
		// void addFromOther(const Iterator from, const Iterator to) {
		// 	if (_elements.size() + std::distance(from, to) > _max_size)
		// 		throw std::logic_error("The new size exceeds the upper limit");

		// 	_elements.insert(from, to);
		// }

		unsigned int	longestSpan(void) const;
		unsigned int	shortestSpan(void) const;
		unsigned int	shortestSpan2(void) const;
};

#endif
