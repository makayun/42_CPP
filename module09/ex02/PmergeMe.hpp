/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FJDeque.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:07:53 by mmakagon          #+#    #+#             */
/*   Updated: 2025/01/09 15:36:12 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FJDeque_HPP
#define FJDeque_HPP

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

template<typename T>
struct SmallerChunksDeque {
	const std::deque<T>& deq;
	const std::size_t chunk_size;

	SmallerChunksDeque(std::deque<T>& d, std::size_t cs) : deq(d), chunk_size(cs) {}

	bool operator()(const int& value) const {
		size_t i = 0;
		for ( ; i < deq.size(); ++i)
			if (&deq[i] == &value)
				break;

		return (i / chunk_size) % 2 != 0;
	}
};

template<typename T>
void Jacubsthal(T& jcbsthl, size_t size) {
	jcbsthl.clear(); // just in case
	jcbsthl.push_back(0);
	size_t	current_jcb = 1;
	size_t	next_jcb = 3;

	while (jcbsthl.size() < size) {
		size_t i = next_jcb;
		while (i > current_jcb)
			if (--i < size)
				jcbsthl.push_back(i);
		next_jcb += current_jcb * 2;
		current_jcb = next_jcb - current_jcb * 2;
	}
}

class FJDeque
{
	private:
		std::deque<int>&	a;
		size_t				comparisons;

		void wrap(const size_t chunk_size);
		void unwrap(const size_t chunk_size);
		void makeTail(std::deque<int>& tail, const size_t chunk_size);
		void smallerChunksToB(std::deque<int>& b, const size_t chunk_size);
		void merge(const std::deque<int>& b, const size_t chunk_size);
		void firstBToTheLeft(const std::deque<int>& b, const size_t chunk_size);
		void insertion(std::deque<int>::const_iterator a_l_it, const std::deque<int>::const_iterator& a_r_it,
						const std::deque<int>::const_iterator& b_l_it, const size_t chunk_size);
		void insertTwo(std::deque<int>::const_iterator& a_l_it, const std::deque<int>::const_iterator& b_l_it, const size_t chunk_size);
		void insertThree(const std::deque<int>::const_iterator& a_mid_it, const std::deque<int>::const_iterator& b_l_it, const size_t chunk_size);

	public:
		FJDeque(std::deque<int>& in_arr);
		explicit	FJDeque(const FJDeque &copy);
		FJDeque&	operator=(const FJDeque &copy);
		~FJDeque();

		void sort(void);
};

#endif
