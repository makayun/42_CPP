/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:33:58 by mmakagon          #+#    #+#             */
/*   Updated: 2024/11/01 14:44:20 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

namespace whatever
{
	template<typename T>
	void swap(T& a, T& b) {
		T c = a;
		a = b;
		b = c;
	}

	template<typename T>
	T max(const T& x,const T& y) {
		return ((x > y) ? x : y);
	}

	template<typename T>
	T min(const T& x, const T& y) {
		return ((x < y) ? x : y);
	}
}

#endif
