/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:44:53 by mmakagon          #+#    #+#             */
/*   Updated: 2024/11/06 15:19:07 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _size(0) {}

Span::Span(const unsigned int N) : _size(N) {
	_elements.reserve(N);
}

Span::Span(const Span& copy) {
	*this = copy;
}

Span& Span::operator=(const Span& copy) {
	if (this != &copy)

	return (*this);
}

Span::~Span() {
}
