#include "FJVector.hpp"

/* VERY ORTHODOX AND CANNONICAL */

FJVector::FJVector(std::vector<int>& in_arr) : a(in_arr), comparisons(0) {}

FJVector::FJVector(const FJVector &copy) : a(copy.a), comparisons(0) {}

FJVector &FJVector::operator=(const FJVector &copy) {
	if (this != &copy) {
		this->a = copy.a;
		this->comparisons = 0;
	}
	return (*this);
}

FJVector::~FJVector(void) {}

/* SORTING */

void FJVector::sort(void) {
	size_t chunk_size = 1;

	while (a.size() / chunk_size > 1) {
		SECTION("\nWrap");
		PRINT_VAR(chunk_size);
		wrap(static_cast<std::ptrdiff_t>(chunk_size));
		PRINT_VAR(a);
		chunk_size *= 2;
	}
	chunk_size /= 2;
	while (chunk_size > 0) {
		SECTION("\nUnwrap");
		PRINT_VAR(chunk_size);
		unwrap(chunk_size);
		PRINT_VAR(a);
		chunk_size /= 2;
	}
	PRINT_VAR(comparisons);
}

void FJVector::wrap(const std::ptrdiff_t chunk_size) {
	std::vector<int>::iterator a_l = a.begin() + chunk_size;
	std::vector<int>::iterator b_l = a.begin();
	std::vector<int>::iterator a_r;

	while (a.end() - a_l >= chunk_size) {
		++comparisons;
		if (*a_l > *b_l) {
			a_r = a_l + chunk_size;
			std::swap_ranges(a_l, a_r, b_l);
		}
		a_l += chunk_size * 2;
		b_l += chunk_size * 2;
	}
}

void FJVector::unwrap(const size_t chunk_size) {
	std::vector<int>	b;
	std::vector<int>	tail;

	makeTail(tail, chunk_size);
	smallerChunksToB(b, chunk_size);
	SECTION("Before merge");
	PRINT_VAR(a);
	PRINT_VAR(b);
	PRINT_VAR(tail);
	merge(b, chunk_size);

	a.insert(a.end(), tail.begin(), tail.end());
}

void FJVector::makeTail(std::vector<int>& tail, const size_t chunk_size) {
	tail.resize(a.size() % chunk_size);
	if (tail.size()) {
		std::vector<int>::iterator tail_in_a = a.end() - tail.size();
		std::copy(tail_in_a, a.end(), tail.begin());
		a.resize(a.size() - tail.size());
	}
}

void FJVector::smallerChunksToB(std::vector<int>& b, const size_t chunk_size) {
	std::stable_partition(a.begin(), a.end(), SmallerChunksVector<int>(a, chunk_size));

	const size_t chunks_count = a.size() / chunk_size;
	b.resize(chunks_count / 2 * chunk_size);

	std::vector<int>::iterator a_mid = a.begin() + b.size();
	std::copy(a.begin(), a_mid, b.begin());
	a.erase(a.begin(), a_mid);

	// If there's an unpaired chunk - move it to 'b'
	if (a.size() > b.size()) {
		b.insert(b.end(), a.end() - chunk_size, a.end());
		a.resize(a.size() - chunk_size);
	}
}

void FJVector::merge(std::vector<int>& b, const size_t chunk_size) {

	firstBToTheLeft(b, chunk_size);

	const size_t chunks_in_b = b.size() / chunk_size;

	if (chunks_in_b > 1) {
		std::vector<size_t>	jcbsthl;
		generateJacubsthal(jcbsthl, chunks_in_b);
		std::vector<int>::iterator a_r;
		std::vector<int>::iterator b_l;

		for (size_t i = 1; i < jcbsthl.size(); ++i) {
			a_r = a.begin() + (jcbsthl[i] + i) * chunk_size;
			b_l = b.begin() + jcbsthl[i] * chunk_size;

			insertion(a.begin(), a_r, b_l, chunk_size);
		}
	}
}

inline void FJVector::firstBToTheLeft(const std::vector<int>& b, const size_t chunk_size) {
	a.insert(a.begin(), b.begin(), b.begin() + chunk_size);
}

void FJVector::insertion(std::vector<int>::iterator a_l_it,
						const std::vector<int>::iterator& a_r_it,
						const std::vector<int>::iterator& b_l_it,
						const size_t chunk_size)
{
	const size_t distance = a_r_it - a_l_it;
	const size_t a_mid_index = distance / chunk_size / 2 * chunk_size;
	std::vector<int>::iterator a_mid_it = a_l_it + a_mid_index;

	if (distance / chunk_size <= 3)
		insert(a_mid_it, b_l_it, chunk_size);
	else if (*b_l_it > *a_mid_it) {
		++comparisons;
		insertion(a_mid_it + chunk_size, a_r_it, b_l_it, chunk_size);
	}
	else {
		++comparisons;
		insertion(a_l_it, a_mid_it, b_l_it, chunk_size);
	}
}

void FJVector::insert(std::vector<int>::iterator& a_l_it,
						const std::vector<int>::iterator& b_l_it,
						const size_t chunk_size)
{
	std::vector<int>::iterator b_r_it = b_l_it + chunk_size;

	++comparisons;
	(*b_l_it > *a_l_it) ? (a_l_it += chunk_size) : (a_l_it -= chunk_size);

	if (a_l_it != a.end()) {
		++comparisons;
		a_l_it += (*b_l_it > *a_l_it) * chunk_size;
	}
	a.insert(a_l_it, b_l_it, b_r_it);
}

size_t FJVector::getSize(void) const{
	return(a.size());
}
