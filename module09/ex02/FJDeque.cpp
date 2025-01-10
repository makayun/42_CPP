/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FJDeque.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:37:04 by mmakagon          #+#    #+#             */
/*   Updated: 2025/01/10 23:52:07 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FJDeque.hpp"

/* VERY ORTHODOX AND CANNONICAL */

FJDeque::FJDeque(std::deque<int>& in_arr) : arr(in_arr), comparisons(0) {}

FJDeque::FJDeque(const FJDeque &copy) : arr(copy.arr), comparisons(0) {}

FJDeque &FJDeque::operator=(const FJDeque &copy) {
	if (this != &copy) {
		this->arr = copy.arr;
		this->comparisons = 0;
	}
	return (*this);
}

FJDeque::~FJDeque(void) {}

/* SORTING */

void FJDeque::sort(void) {
	size_t chunk_size = 1;

	while (arr.size() / chunk_size > 1) {
		wrap(static_cast<ptrdiff_t>(chunk_size));
		chunk_size *= 2;
	}
	chunk_size /= 2;
	while (chunk_size > 0) {
		unwrap(chunk_size);
		chunk_size /= 2;
	}
	PRINT_VAR(comparisons);
}

void FJDeque::wrap(const ptrdiff_t chunk_size) {
	std::deque<int>::iterator a_l = arr.begin();
	std::deque<int>::iterator b_l = arr.begin();
	std::deque<int>::iterator a_r;

	std::advance(a_l, chunk_size);

	while (std::distance(a_l, arr.end()) >= chunk_size) {
		++comparisons;
		if (*a_l > *b_l) {
			a_r = a_l;
			std::advance(a_r, chunk_size);
			std::swap_ranges(a_l, a_r, b_l);
		}
		std::advance(a_l, chunk_size * 2);
		std::advance(b_l, chunk_size * 2);
	}
}

void FJDeque::unwrap(const size_t chunk_size) {
	std::deque<int>	b;

	smallerChunksToB(b, static_cast<ptrdiff_t>(chunk_size));
	merge(b, chunk_size);

	std::copy(a.cbegin(), a.cend(), arr.begin());
	a.clear();
}

void FJDeque::smallerChunksToB(std::deque<int>& b, const ptrdiff_t chunk_size) {
	const size_t size_without_tail = arr.size() - (arr.size() % chunk_size);
	const size_t size_of_paired_chunks = arr.size() / chunk_size / 2 * chunk_size * 2;
	size_t	i = 0;

	for ( ; i < size_of_paired_chunks; ++i)
		(i / chunk_size) % 2 == 0 ? a.push_back(arr.at(i)) : b.push_back(arr.at(i));

	for ( ; i < size_without_tail; ++i)
		b.push_back(arr.at(i));
}

void FJDeque::merge(const std::deque<int>& b, const size_t chunk_size) {

	firstBToTheLeft(b, chunk_size);

	const size_t chunks_in_b = b.size() / chunk_size;

	if (chunks_in_b > 1) {
		std::deque<size_t>	jcbsthl;
		generateJacubsthal(jcbsthl, chunks_in_b);
		std::deque<int>::const_iterator a_r;
		std::deque<int>::const_iterator b_l;

		for (size_t i = 1; i < jcbsthl.size(); ++i) {
			a_r = a.cbegin();
			std::advance(a_r, (jcbsthl.at(i) + i) * chunk_size);

			b_l = b.cbegin();
			std::advance(b_l, (jcbsthl.at(i) * chunk_size));

			insertion(a.begin(), a_r, b_l, chunk_size);
		}
	}

}

void FJDeque::firstBToTheLeft(const std::deque<int>& b, const size_t chunk_size) {
	std::deque<int>::const_iterator b_first_chunk_end = b.begin();
	std::advance(b_first_chunk_end, chunk_size);
	a.insert(a.cbegin(), b.cbegin(), b_first_chunk_end);
}

void FJDeque::insertion(std::deque<int>::const_iterator a_l_it,
						const std::deque<int>::const_iterator& a_r_it,
						const std::deque<int>::const_iterator& b_l_it,
						const size_t chunk_size)
{
	const size_t distance = std::distance(a_l_it, a_r_it);
	const size_t a_mid_index = distance / chunk_size / 2 * chunk_size;
	std::deque<int>::const_iterator a_mid_it = a_l_it;
	std::advance(a_mid_it, a_mid_index);

	if (distance / chunk_size <= 2)
		insertTwo(a_l_it, b_l_it, chunk_size);
	else if (distance / chunk_size == 3)
		insertThree(a_mid_it, b_l_it, chunk_size);
	else if (*b_l_it > *a_mid_it) {
		++comparisons;
		std::advance(a_mid_it, chunk_size);
		insertion(a_mid_it, a_r_it, b_l_it, chunk_size);
	}
	else {
		++comparisons;
		insertion(a_l_it, a_mid_it, b_l_it, chunk_size);
	}
}

void FJDeque::insertTwo(std::deque<int>::const_iterator& a_l_it,
						const std::deque<int>::const_iterator& b_l_it,
						const size_t chunk_size)
{
	std::deque<int>::const_iterator b_r_it = b_l_it;
	std::advance(b_r_it, chunk_size);
	++comparisons;
	while (a_l_it != a.cend() && *b_l_it > *a_l_it) {
		std::advance(a_l_it, chunk_size);
		++comparisons;
	}
	a.insert(a_l_it, b_l_it, b_r_it);
}

void FJDeque::insertThree(std::deque<int>::const_iterator& a_it,
						const std::deque<int>::const_iterator& b_l_it,
						const size_t chunk_size)
{
	std::deque<int>::const_iterator b_r_it = b_l_it;
	std::advance(b_r_it, chunk_size);

	++comparisons;
	(*b_l_it > *a_it) ? std::advance(a_it, chunk_size) : std::advance(a_it, -chunk_size);

	++comparisons;
	std::advance(a_it, (*b_l_it > *a_it) * chunk_size);
	a.insert(a_it, b_l_it, b_r_it);
}