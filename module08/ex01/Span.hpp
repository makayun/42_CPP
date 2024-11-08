/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:44:56 by mmakagon          #+#    #+#             */
/*   Updated: 2024/11/08 15:30:35 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>

class Span
{
	private:
		std::multiset<int>	_elements;
		unsigned int		_max_size;

	public:
		Span();
		explicit		Span(const unsigned int N);
		Span(const Span& copy);
		Span&			operator=(const Span& copy);
		~Span();

		void			addNumber(const int& n);
		unsigned int	longestSpan(void) const;
		unsigned int	shortestSpan(void) const;
		unsigned int	shortestSpan2(void) const;
};

#endif
