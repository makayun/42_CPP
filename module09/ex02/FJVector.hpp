/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FJVector.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:35:23 by mmakagon          #+#    #+#             */
/*   Updated: 2025/01/13 11:52:00 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FJVECTOR_HPP
#define FJVECTOR_HPP

#include <vector>
#include "PmergeMe.hpp"

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& in) {
	for (typename std::vector<T>::const_iterator it = in.begin(); it != in.end(); ++it)
		out << *it << " ";
	return (out);
}

template<typename T>
struct SmallerChunksVector {
	const std::vector<T>&	vec;
	const size_t			chunk_size;

	SmallerChunksVector(const std::vector<T>& v, const size_t cs) : vec(v), chunk_size(cs) {}

	bool operator()(const int& value) const {
		std::ptrdiff_t index = &value - &vec[0];
		return (index / chunk_size) % 2 != 0;
	}
};

class FJVector
{
	private:
		std::vector<int>&	a;
		size_t				comparisons;

		void wrap(const std::ptrdiff_t chunk_size);
		void unwrap(const size_t chunk_size);
		void makeTail(std::vector<int>& tail, const size_t chunk_size);
		void smallerChunksToB(std::vector<int>& b, const size_t chunk_size);
		void merge(std::vector<int>& b, const size_t chunk_size);
		void firstBToTheLeft(const std::vector<int>& b, const size_t chunk_size);
		void insertion(std::vector<int>::iterator a_l_it, const std::vector<int>::iterator& a_r_it,
						const std::vector<int>::iterator& b_l_it, const size_t chunk_size);
		void insertTwo(std::vector<int>::iterator& a_l_it, const std::vector<int>::iterator& b_l_it, const size_t chunk_size);
		void insert(std::vector<int>::iterator& a_mid_it, const std::vector<int>::iterator& b_l_it, const size_t chunk_size);

	public:
		explicit	FJVector(std::vector<int>& in_arr);
		explicit	FJVector(const FJVector &copy);
		FJVector&	operator=(const FJVector &copy);
		~FJVector();

		void sort(void);
		size_t	getSize(void) const;
};

#endif
