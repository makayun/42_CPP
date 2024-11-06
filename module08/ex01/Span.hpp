/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:44:56 by mmakagon          #+#    #+#             */
/*   Updated: 2024/11/06 15:18:56 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
	private:
		std::vector<int>	_elements;
		unsigned int		_size;

	public:
		Span();
		explicit	Span(const unsigned int N);
		explicit	Span(const Span& copy);
		Span&		operator=(const Span& copy);
		~Span();
};

#endif
