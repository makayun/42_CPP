/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:44:06 by mmakagon          #+#    #+#             */
/*   Updated: 2025/01/09 08:16:52 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static size_t comparisons = 0;

// ./PmergeMe `shuf -i 1-100 -n 21 | tr "\n" " "`
// ./PmergeMe `jot -r 21 1 100 | tr '\n' ' '`

void findMe(const std::deque<int>& d) {
	for (size_t i = 1; i < d.size(); ++i) {
		if (d.at(i) < d.at(i - 1))
			std::cout 	<< "\nIndex: " << i
						<< "\nNumber: " << d.at(i)
						<< "\nPrevious: " << d.at(i - 1)
						<< std::endl;
	}
}

void dequeJacubsthal(std::deque<size_t>& jcbsthl, size_t size) {
	SECTION("Jacubsthal array generation");
	PRINT_VAR(size);
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
	PRINT_VAR(jcbsthl);
}

struct SmallerChunks {
	std::deque<int>& deq;
	std::size_t chunk_size;

	SmallerChunks(std::deque<int>& d, std::size_t cs) : deq(d), chunk_size(cs) {}

	bool operator()(const int& value) const {
		std::ptrdiff_t index = &value - &deq[0];

		return (index / chunk_size) % 2 != 0;
	}
};

void fjDequeWrap(std::deque<int>& in_arr, size_t chunk_size) {
	SECTION("\nWrapping iteration");
	PRINT_VAR(chunk_size);

	std::deque<int>::iterator a;
	std::deque<int>::iterator b;

	for (size_t i = chunk_size; i < in_arr.size(); i += chunk_size * 2) {
		a = in_arr.begin();
		std::advance(a, i);

		b = in_arr.begin();
		std::advance(b, i - chunk_size);

		if (std::distance(a, in_arr.end()) >= static_cast<ptrdiff_t>(chunk_size)) {
			std::deque<int>::iterator a_end = a;
			std::advance(a_end, chunk_size);

			if (*a > *b)
				std::swap_ranges(a, a_end, b);
		}
		++comparisons;
	}
	SECTION("After wrapping:");
	PRINT_VAR(in_arr);
	PRINT_VAR(comparisons);
}

void fjDequeMakeTail(std::deque<int>& a, std::deque<int>& tail, size_t chunk_size) {
	tail.resize(a.size() % chunk_size);
	if (tail.size()) {
		SECTION("Making a tail");
		std::deque<int>::const_iterator tail_in_a = a.cend();
		std::advance(tail_in_a, -tail.size());
		std::copy(tail_in_a, a.cend(), tail.begin());
		a.resize(a.size() - tail.size());
		PRINT_VAR(a);
		PRINT_VAR(tail);
	}
}

void fjDequeSmallerChunksToB(std::deque<int>& a, std::deque<int>& b, std::deque<int>& unpaired_chunk, size_t chunk_size) {
	SECTION("Moving smaller elements to 'b', first move them to the beginning of 'a' using std::stable_partition");
	std::stable_partition(a.begin(), a.end(), SmallerChunks(a, chunk_size));
	SECTION("'a' after partition:");
	PRINT_VAR(a);

	const size_t chunks_count = a.size() / chunk_size;
	b.resize(chunks_count / 2 * chunk_size);

	std::deque<int>::const_iterator a_mid = a.cbegin();
	std::advance(a_mid, b.size());
	std::copy(a.cbegin(), a_mid, b.begin());
	a.erase(a.cbegin(), a_mid);

	// If there's an unpaired chunk - move it to 'unpaired chunk'
	if (a.size() > b.size()) {
		std::deque<int>::const_iterator unpaired_it = a.end();
		std::advance(unpaired_it, -chunk_size);
		unpaired_chunk.insert(unpaired_chunk.begin(), unpaired_it, a.cend());
		a.resize(a.size() - chunk_size);
	}
	SECTION("After 'b' is created:");
	PRINT_VAR(a);
	PRINT_VAR(b);
	PRINT_VAR(unpaired_chunk);
}

void fjDequeFirstBToTheLeft(std::deque<int>& a, const std::deque<int>& b, const size_t chunk_size) {
	std::deque<int>::const_iterator b_first_chunk_end = b.begin();
	std::advance(b_first_chunk_end, chunk_size);
	a.insert(a.cbegin(), b.cbegin(), b_first_chunk_end);
}

void fjDequeInsertion(	std::deque<int>& a,
						const std::deque<int>::const_iterator& b_left,
						const size_t max_index,
						const size_t chunk_size)
{
	size_t a_index = max_index / chunk_size / 2 * chunk_size;
	std::deque<int>::const_iterator b_right = b_left;
	std::advance(b_right, chunk_size);

	try
	{
		PRINT_VAR(max_index);
		if (max_index < a.size()) {
			PRINT_VAR(a.at(max_index));
		}
		PRINT_VAR(a_index);
		PRINT_VAR(a.at(a_index));
		PRINT_VAR(*b_left);
	}
	catch(const std::exception& e)
	{
		std::cerr	<< e.what()
					<< "\nChunk size: " << chunk_size
					<< "\nSize: " << a.size()
					<< "\nmax_index: " << max_index
					<< "\na_index: " << a_index
					<< std::endl;
	}


	std::deque<int>::const_iterator a_left = a.cbegin();
	++comparisons;
	try
	{
		if (*b_left < a.at(a_index)) {
			while (a_index >= chunk_size) {
				++comparisons;
				if (*b_left >= a.at(a_index - chunk_size))
					break;
				else
					a_index -= chunk_size;
			}
		}
		else {
			while (a_index < max_index) {
				a_index += chunk_size;
				++comparisons;
				if (*b_left <= a.at(a_index))
					break;
			}
		}
	}
	catch(const std::exception& e)
	{
		a.insert(a.end(), b_left, b_right);
		// findMe(a);
		return;
		// std::cerr << e.what() << '\n';
		// std::cerr << a << std::endl;
	}


	std::advance(a_left, a_index);
	a.insert(a_left, b_left, b_right);
}

void fjDequeMergeMagic(	std::deque<int>& a,
						const std::deque<int>& b,
						const std::deque<int>& unpaired_chunk,
						const std::deque<size_t>& jcbsthl,
						const size_t chunk_size) {

	fjDequeFirstBToTheLeft(a, b, chunk_size);
	SECTION("After moving first chunk to the left of 'a'");
	PRINT_VAR(a);

	for (size_t i = 1; i < jcbsthl.size(); ++i) {
		const size_t max_index = (jcbsthl.at(i) + i) * chunk_size;

		std::deque<int>::const_iterator b_left = b.cbegin();
		std::advance(b_left, (jcbsthl.at(i) * chunk_size));

		fjDequeInsertion(a, b_left, max_index, chunk_size);
		PRINT_VAR(unpaired_chunk);
		PRINT_VAR(a);
		PRINT_VAR(b);
	}
	// if (chunk_size == 1) {
	// 	SECTION("After insertion");
	// 	findMe(a);
	// }
	if (unpaired_chunk.size())
		fjDequeInsertion(a, unpaired_chunk.begin(), a.size(), chunk_size);
}

void fjDequeUnwrap(std::deque<int>& a, size_t chunk_size) {
	SECTION("\nUnwrapping iteration");
	PRINT_VAR(chunk_size);

	std::deque<int>		b;
	std::deque<int>		tail;
	std::deque<int>		unpaired_chunk;
	std::deque<size_t>	jcbsthl_arr;

	fjDequeMakeTail(a, tail, chunk_size);
	fjDequeSmallerChunksToB(a, b, unpaired_chunk, chunk_size);

	{
		const size_t chunks_in_a = a.size() / chunk_size;
		if (chunks_in_a > 1)
			dequeJacubsthal(jcbsthl_arr, chunks_in_a);
	}

	fjDequeMergeMagic(a, b, unpaired_chunk, jcbsthl_arr, chunk_size);

	if (tail.size()) {
		if (chunk_size > 1)
			a.insert(a.end(), tail.cbegin(), tail.cend());
	}
	SECTION("After unwrapping iteration:");
	PRINT_VAR(a);
	PRINT_VAR(comparisons);
}

void fjDequeSort(std::deque<int>& in_arr) {
	size_t chunk_size = 1;

	while (in_arr.size() / chunk_size > 1) {
		fjDequeWrap(in_arr, chunk_size);
		chunk_size *= 2;
	}
	chunk_size /= 2;
	while (chunk_size > 0) {
		fjDequeUnwrap(in_arr, chunk_size);
		chunk_size /= 2;
	}
}



int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Try again" << std::endl;
		return (42);
	}

	std::deque<int>	d;

	{
		std::istringstream	ss;
		long				temp;

		for (int i = 1; i < argc && argv[i]; ++i) {
			ss.clear();
			ss.str(argv[i]);
			if (!(ss >> temp) || temp < 1 || temp > INT_MAX) {
				std::cerr << "Error" << std::endl;
				return (42);
			}
			d.push_back(static_cast<int>(temp));
		}
	}
	std::cout << "Before: " << d << std::endl;
	fjDequeSort(d);
	std::cout << "After: " << d << std::endl;

	// findMe(d);
	assert(std::is_sorted(d.cbegin(), d.cend()));
}
