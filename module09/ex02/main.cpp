
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

struct SmallerChunks {
	std::deque<int>& deq;
	std::size_t chunk_size;

	SmallerChunks(std::deque<int>& d, std::size_t cs) : deq(d), chunk_size(cs) {}

	bool operator()(const int& value) const {
		size_t i = 0;
		for ( ;i < deq.size(); ++i)
			if (&deq[i] == &value)
				break;

		return (i / chunk_size) % 2 != 0;
	}
};

void fjDequeWrap(std::deque<int>& in_arr, size_t chunk_size) {
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
			++comparisons;
		}
	}
}

void fjDequeMakeTail(std::deque<int>& a, std::deque<int>& tail, size_t chunk_size) {
	tail.resize(a.size() % chunk_size);
	if (tail.size()) {
		std::deque<int>::const_iterator tail_in_a = a.cend();
		std::advance(tail_in_a, -tail.size());
		std::copy(tail_in_a, a.cend(), tail.begin());
		a.resize(a.size() - tail.size());
	}
}

void fjDequeSmallerChunksToB(std::deque<int>& a, std::deque<int>& b, size_t chunk_size) {
	std::stable_partition(a.begin(), a.end(), SmallerChunks(a, chunk_size));

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

void fjDequeFirstBToTheLeft(std::deque<int>& a, const std::deque<int>& b, const size_t chunk_size) {
	std::deque<int>::const_iterator b_first_chunk_end = b.begin();
	std::advance(b_first_chunk_end, chunk_size);
	a.insert(a.cbegin(), b.cbegin(), b_first_chunk_end);
}

void fjDequeInsertTwo(	std::deque<int>& a,
						std::deque<int>::const_iterator& a_l_it,
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

void fjDequeInsertThree(std::deque<int>& a,
						const std::deque<int>::const_iterator& a_mid_it,
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

void fjDequeInsertion(	std::deque<int>& a,
						std::deque<int>::const_iterator a_l_it,
						const std::deque<int>::const_iterator& a_r_it,
						const std::deque<int>::const_iterator& b_l_it,
						const size_t chunk_size)
{
	const size_t distance = std::distance(a_l_it, a_r_it);
	const size_t a_mid_index = distance / chunk_size / 2 * chunk_size;
	std::deque<int>::const_iterator a_mid_it = a_l_it;
	std::advance(a_mid_it, a_mid_index);

	if (distance / chunk_size <= 2)
		fjDequeInsertTwo(a, a_l_it, b_l_it, chunk_size);
	else if (distance / chunk_size == 3)
		fjDequeInsertThree(a, a_mid_it, b_l_it, chunk_size);
	else if (*b_l_it > *a_mid_it) {
		++comparisons;
		std::advance(a_mid_it, chunk_size);
		fjDequeInsertion(a, a_mid_it, a_r_it, b_l_it, chunk_size);
	}
	else
		fjDequeInsertion(a, a_l_it, a_mid_it, b_l_it, chunk_size);

}

void fjDequeMergeMagic(std::deque<int>& a, const std::deque<int>& b, const size_t chunk_size) {

	fjDequeFirstBToTheLeft(a, b, chunk_size);

	std::deque<size_t>	jcbsthl;
	const size_t chunks_in_b = b.size() / chunk_size;
	if (chunks_in_b > 1)
		dequeJacubsthal(jcbsthl, chunks_in_b);

	for (size_t i = 1; i < jcbsthl.size(); ++i) {
		std::deque<int>::const_iterator a_r = a.cbegin();
		std::advance(a_r, (jcbsthl.at(i) + i) * chunk_size);

		std::deque<int>::const_iterator b_left = b.cbegin();
		std::advance(b_left, (jcbsthl.at(i) * chunk_size));

		fjDequeInsertion(a, a.begin(), a_r, b_left, chunk_size);
	}
}

void fjDequeUnwrap(std::deque<int>& a, size_t chunk_size) {

	std::deque<int>		b;
	std::deque<int>		tail;

	fjDequeMakeTail(a, tail, chunk_size);
	fjDequeSmallerChunksToB(a, b, chunk_size);
	fjDequeMergeMagic(a, b, chunk_size);

	if (tail.size()) {
		if (chunk_size > 1)
			a.insert(a.end(), tail.cbegin(), tail.cend());
	}
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
	std::deque<int> control_d;

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
			control_d.push_back(static_cast<int>(temp));
		}
	}

	assert(d == control_d);

	std::cout << "Before: " << d << std::endl;
	fjDequeSort(d);
	std::cout << "After: " << d << std::endl;
	PRINT_VAR(comparisons);
	std::sort(control_d.begin(), control_d.end());
	assert(d == control_d);
}
