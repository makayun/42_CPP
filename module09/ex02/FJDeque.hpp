/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FJDeque.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:29:18 by mmakagon          #+#    #+#             */
/*   Updated: 2025/01/10 13:10:27 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FJDEQUE_HPP
#define FJDEQUE_HPP

#include "PmergeMe.hpp"
#include <deque>

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::deque<T>& in) {
	for (typename std::deque<T>::const_iterator it = in.cbegin(); it != in.end(); ++it)
		out << *it << " ";
	return (out);
}

template<typename T>
struct SmallerChunksDeque {
	const std::deque<T>& deq;
	const std::size_t chunk_size;

	SmallerChunksDeque(const std::deque<T>& d, const std::size_t cs) : deq(d), chunk_size(cs) {}

	bool operator()(const int& value) const {
		size_t i = 0;
		for ( ; i < deq.size(); ++i)
			if (&deq[i] == &value)
				break;

		return (i / chunk_size) % 2 != 0;
	}
};

class FJDeque
{
	private:
		std::deque<int>&	a;
		size_t				comparisons;

		void wrap(const ptrdiff_t chunk_size);
		void unwrap(const size_t chunk_size);
		void makeTail(std::deque<int>& tail, const size_t chunk_size);
		void smallerChunksToB(std::deque<int>& b, const size_t chunk_size);
		void merge(const std::deque<int>& b, const size_t chunk_size);
		void firstBToTheLeft(const std::deque<int>& b, const size_t chunk_size);
		void insertion(std::deque<int>::const_iterator a_l_it, const std::deque<int>::const_iterator& a_r_it,
						const std::deque<int>::const_iterator& b_l_it, const size_t chunk_size);
		void insertTwo(std::deque<int>::const_iterator& a_l_it, const std::deque<int>::const_iterator& b_l_it, const size_t chunk_size);
		void insertThree(std::deque<int>::const_iterator& a_mid_it, const std::deque<int>::const_iterator& b_l_it, const size_t chunk_size);

	public:
		explicit	FJDeque(std::deque<int>& in_arr);
		explicit	FJDeque(const FJDeque &copy);
		FJDeque&	operator=(const FJDeque &copy);
		~FJDeque();

		void sort(void);
};

#endif
