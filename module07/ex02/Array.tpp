/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:07:40 by mmakagon          #+#    #+#             */
/*   Updated: 2024/11/06 11:37:12 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template<typename T>
Array<T>::Array(void) : _elements(NULL), _size(0) {}

template<typename T>
Array<T>::Array(const unsigned int n) : _elements(new T[n]()), _size(n) {}

template<typename T>
Array<T>::Array(const Array<T>& copy) : _elements(new T[copy.size()]), _size(copy.size()) {
	for (size_t i = 0; i < copy.size(); i++)
		this->_elements[i] = copy._elements[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& copy) {
	if (this != &copy) {
		delete[] this->_elements;
		this->_elements = new T[copy.size()];
		for (size_t i = 0; i < copy._size; i++)
			this->_elements[i] = copy._elements[i];
	}
	return (*this);
}

template<typename T>
Array<T>::~Array() {
	delete[] (_elements);
}

template<typename T>
T& Array<T>::operator[](long n) const {
	if (n < 0 || n >= static_cast<long>(_size))
		throw std::out_of_range("Index is out of bonds");
	return (_elements[n]);
}

template<typename T>
size_t Array<T>::size() const {
	return (this->_size);
}

#endif
