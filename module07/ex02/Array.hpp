/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:46:05 by mmakagon          #+#    #+#             */
/*   Updated: 2024/11/01 19:10:22 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {
	private:
		T*		_elements;
		ssize_t _size;

	public:
		Array();
		explicit	Array(unsigned int n);
		explicit	Array(const Array& copy);
		Array&		operator=(const Array& copy);
		T			operator[](long n) const;

};

#include "Array.tpp"

#endif
