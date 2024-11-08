/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:44:53 by mmakagon          #+#    #+#             */
/*   Updated: 2024/11/08 15:28:55 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _max_size(0) {}

Span::Span(const unsigned int N) : _max_size(N) {}

Span::Span(const Span& copy) {
	*this = copy;
}

Span& Span::operator=(const Span& copy) {
	if (this != &copy)	{
		this->_elements.clear();
		this->_elements.insert(copy._elements.begin(), std::next(copy._elements.begin(), this->_max_size));
	}
	return (*this);
}

Span::~Span() {
}

void Span::addNumber(const int& n) {
	if (_elements.size() >= _max_size)
		throw (std::runtime_error("Reached the maximum capacity"));
	_elements.insert(n);
}

unsigned int Span::longestSpan(void) const {
	if (_elements.size() < 2)
		throw std::logic_error("Not enough elements!");
	else
		return (*std::prev(_elements.end()) - *_elements.begin());
}

unsigned int Span::shortestSpan(void) const {
	if (_elements.size() < 2)
		throw std::logic_error("Not enough elements!");

	std::vector<int> differences(_elements.size());
	std::adjacent_difference(_elements.begin(), _elements.end(), differences.begin());
	return (*std::min_element(std::next(_elements.begin()), _elements.end()));
}

unsigned int Span::shortestSpan2(void) const {
	if (_elements.size() < 2)
		throw std::logic_error("Not enough elements!");

	std::set<unsigned int> differences;
	std::set<int>::iterator a = _elements.begin();
	std::set<int>::iterator b;
	do {
		b = std::next(a);
		differences.insert(*b - *a);
		a = std::next(a);
	} while (a != _elements.end());
	return (*differences.begin());
}
