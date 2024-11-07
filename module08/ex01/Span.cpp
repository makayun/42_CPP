/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:44:53 by mmakagon          #+#    #+#             */
/*   Updated: 2024/11/07 15:21:30 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _max_size(0) {}

Span::Span(const unsigned int N) : _max_size(N) {
	_elements.reserve(N);
}

Span::Span(const Span& copy) {
	*this = copy;
}

Span& Span::operator=(const Span& copy) {
	if (this != &copy)	{
		std::copy	( copy._elements.begin()
					, copy._elements.begin() + this->_max_size
					, this->_elements.begin() );
	}
	return (*this);
}

Span::~Span() {
}

void Span::addNumber(const int& n) {
	if (_elements.size() >= _max_size)
		throw (std::runtime_error("Reached the maximum capacity"));
	_elements.push_back(n);
}
