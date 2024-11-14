/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:52:48 by mmakagon          #+#    #+#             */
/*   Updated: 2024/11/14 14:44:40 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>



template<typename T>
class MutantStack : public std::stack<T, std::deque<T> > {
public:
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;

	iterator begin() {
		return this->c.begin();
	}

	iterator end() {
		return this->c.end();
	}

	const_iterator begin() const {
		return this->c.begin();
	}

	const_iterator end() const {
		return this->c.end();
	}

	T& front() {
		return this->c.front();
	}

	T& back() {
		return this->c.back();
	}
};

#include "MutantStack.tpp"

#endif
