/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FJDeque.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:40:06 by mmakagon          #+#    #+#             */
/*   Updated: 2025/01/09 15:40:25 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//////////////////// DEQUE ////////////////////

/* VERY ORTHODOX AND CANNONICAL */

FJDeque::FJDeque(std::deque<int>& in_arr) : a(in_arr), comparisons(0) {}

FJDeque::FJDeque(const FJDeque &copy) : a(copy.a), comparisons(0) {}

FJDeque &FJDeque::operator=(const FJDeque &copy) {
	if (this != &copy) {
		this->a = copy.a;
		this->comparisons = 0;
	}
	return (*this);
}

FJDeque::~FJDeque(void) {}

/* SORTING */

void FJDeque::sort(void) {
	size_t chunk_size = 1;

	while (a.size() / chunk_size > 1) {
		wrap(chunk_size);
		chunk_size *= 2;
	}
	chunk_size /= 2;
	while (chunk_size > 0) {
		unwrap(chunk_size);
		chunk_size /= 2;
	}
}

void FJDeque::wrap(const size_t chunk_size) {
	std::deque<int>::iterator a_l = a.begin();
	std::deque<int>::iterator b_l = a.begin();
	std::deque<int>::iterator a_r;

	std::advance(a_l, chunk_size);

	while (std::distance(a_l, a.end()) >= static_cast<ptrdiff_t>(chunk_size)) {
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
	std::deque<int>	tail;

	makeTail(tail, chunk_size);
	smallerChunksToB(b, chunk_size);
	merge(b, chunk_size);

	a.insert(a.end(), tail.cbegin(), tail.cend());
}

void FJDeque::makeTail(std::deque<int>& tail, const size_t chunk_size) {
	tail.resize(a.size() % chunk_size);
	if (tail.size()) {
		std::deque<int>::const_iterator tail_in_a = a.cend();
		std::advance(tail_in_a, -tail.size());
		std::copy(tail_in_a, a.cend(), tail.begin());
		a.resize(a.size() - tail.size());
	}
}

void FJDeque::smallerChunksToB(std::deque<int>& b, const size_t chunk_size) {
	std::stable_partition(a.begin(), a.end(), SmallerChunksDeque<int>(a, chunk_size));

	const size_t chunks_count = a.size() / chunk_size;
	b.resize(chunks_count / 2 * chunk_size);

	std::deque<int>::const_iterator a_mid = a.cbegin();
	std::advance(a_mid, b.size());
	std::copy(a.cbegin(), a_mid, b.begin());
	a.erase(a.cbegin(), a_mid);

	// If there's an unpaired chunk - move it to 'b'
	if (a.size() > b.size()) {
		std::deque<int>::const_iterator unpaired_it = a.end();
		std::advance(unpaired_it, -chunk_size);
		b.insert(b.end(), unpaired_it, a.cend());
		a.resize(a.size() - chunk_size);
	}
}

void FJDeque::merge(const std::deque<int>& b, const size_t chunk_size) {

	firstBToTheLeft(b, chunk_size);

	std::deque<size_t>	jcbsthl;
	const size_t chunks_in_b = b.size() / chunk_size;
	if (chunks_in_b > 1)
		Jacubsthal(jcbsthl, chunks_in_b);

	for (size_t i = 1; i < jcbsthl.size(); ++i) {
		std::deque<int>::const_iterator a_r = a.cbegin();
		std::advance(a_r, (jcbsthl.at(i) + i) * chunk_size);

		std::deque<int>::const_iterator b_l = b.cbegin();
		std::advance(b_l, (jcbsthl.at(i) * chunk_size));

		insertion(a.begin(), a_r, b_l, chunk_size);
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
	else
		insertion(a_l_it, a_mid_it, b_l_it, chunk_size);
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

void FJDeque::insertThree(const std::deque<int>::const_iterator& a_mid_it,
						const std::deque<int>::const_iterator& b_l_it,
						const size_t chunk_size)
{
	std::deque<int>::const_iterator a_temp = a_mid_it;
	std::deque<int>::const_iterator b_r_it = b_l_it;
	std::advance(b_r_it, chunk_size);

	if (*b_l_it > *a_mid_it) {
		++comparisons;
		std::advance(a_temp, chunk_size);
		++comparisons;
		if (a_temp == a.end() || *b_l_it < *a_temp) {
			a.insert(a_temp, b_l_it, b_r_it);
		}
		else {
			std::advance(a_temp, chunk_size);
			a.insert(a_temp, b_l_it, b_r_it);
		}
	}
	else {
		std::advance(a_temp, -chunk_size);
		if (*b_l_it > *a_temp) {
			++comparisons;
			a.insert(a_mid_it, b_l_it, b_r_it);
		}
		else
			a.insert(a_temp, b_l_it, b_r_it);
	}
}
