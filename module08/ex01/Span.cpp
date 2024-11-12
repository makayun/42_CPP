/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:44:53 by mmakagon          #+#    #+#             */
/*   Updated: 2024/11/11 11:53:22 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


/* CONSTRUCT - DESTRUCT */

Span::Span(void) : _max_size(0) {}

Span::Span(const unsigned int N) : _max_size(N) {}

Span::Span(const Span& copy) {
	*this = copy;
}

Span& Span::operator=(const Span& copy) {
	if (this != &copy)	{
		this->_elements.clear();
		this->_elements.insert(copy._elements.begin(),
								copy._elements.size() > this->_max_size
								? std::next(copy._elements.begin(), this->_max_size)
								: copy._elements.end());
	}
	return (*this);
}

Span::~Span() {}


/* ADDING / DELETING ELEMENTS */

void Span::addNumber(const int& n) {
	if (_elements.size() >= _max_size)
		throw (std::runtime_error("Reached the maximum capacity"));

	_elements.insert(n);
}

void Span::fillRandom(const int& number_of_elements) {
	if (number_of_elements + _elements.size() > _max_size)
		throw (std::logic_error("That amount of numbers will exceed the upper limit"));

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(-100, 100);
	for (int i = 0; i < number_of_elements; ++i)
		_elements.insert(dis(gen));
}

void Span::clear(void) {
	_elements.clear();
}

const int& Span::operator[](const int& n) const {
	if (n < 0 || n >= static_cast<int>(_elements.size()))
		throw std::out_of_range("Index is out of bounds");

	std::set<int>::iterator it = _elements.begin();
	std::advance(it, n);
	return *it;
}


/* SPANS (OR DISTANCES, IF YOU PREFER) */

unsigned int Span::longestSpan(void) const {
	if (_elements.size() < 2)
		throw std::logic_error("Not enough elements!");

	return (*std::prev(_elements.end()) - *_elements.begin());
}

unsigned int Span::shortestSpan(void) const {
	if (_elements.size() < 2)
		throw std::logic_error("Not enough elements!");

	std::vector<unsigned int> differences(_elements.size());
	std::adjacent_difference(_elements.begin(), _elements.end(), differences.begin());
	return (*std::min_element(std::next(differences.begin()), differences.end()));
}

unsigned int Span::shortestSpan2(void) const {
	if (_elements.size() < 2)
		throw std::logic_error("Not enough elements!");

	std::set<unsigned int> differences;
	std::set<int>::iterator a = _elements.begin();
	std::set<int>::iterator b = std::next(a);
	while (b != _elements.end()) {
		differences.insert(*b - *a);
		++a;
		++b;
	}
	return (*differences.begin());
}
