/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:46:05 by mmakagon          #+#    #+#             */
/*   Updated: 2024/11/04 14:17:37 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {
	private:
		T*		_elements;
		size_t	_size;

	public:
		Array();
		explicit	Array(const unsigned int n);
		Array(const Array& copy);
		Array&		operator=(const Array& copy);
		~Array();
		T&			operator[](long n) const;

		size_t		size() const;

};

#include "Array.tpp"

#endif
