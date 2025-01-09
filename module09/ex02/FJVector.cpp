#include "FJVector.hpp"

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

void FJVector::sort(void)  {
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

void FJVector::wrap(const size_t chunk_size) {
	std::vector<int>::iterator a_l = a.begin() + chunk_size;
	std::vector<int>::iterator b_l = a.begin();
	std::vector<int>::iterator a_r;

	while (std::distance(a_l, a.end()) >= static_cast<ptrdiff_t>(chunk_size)) {
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
	std::vector<int> b;
	std::vector<int> tail;

	makeTail(tail, chunk_size);
	smallerChunksToB(b, chunk_size);
	merge(b, chunk_size);

	a.
}
