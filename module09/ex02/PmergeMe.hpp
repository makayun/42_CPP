/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:07:53 by mmakagon          #+#    #+#             */
/*   Updated: 2025/01/09 10:08:43 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <list>
#include <deque>
#include <climits>

#ifdef DEBUG
#define PRINT_VAR(x) std::cout << #x << ": " << x << std::endl
#define SECTION(x) std::cout << x << std::endl
#else
#define PRINT_VAR(x)
#define SECTION(x)
#endif

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::deque<T>& in) {
	for (typename std::deque<T>::const_iterator it = in.cbegin(); it != in.end(); ++it)
		out << *it << " ";
	return (out);
}

#endif
