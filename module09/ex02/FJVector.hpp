#include <vector>

class FJVector
{
	private:
		std::vector<int>&	a;
		size_t				comparisons;

		void wrap(const size_t chunk_size);
		void unwrap(const size_t chunk_size);
		void makeTail(std::vector<int>& tail, const size_t chunk_size);
		void smallerChunksToB(std::vector<int>& b, const size_t chunk_size);
		void merge(const std::vector<int>& b, const size_t chunk_size);
		void firstBToTheLeft(const std::vector<int>& b, const size_t chunk_size);
		void insertion(std::vector<int>::const_iterator a_l_it, const std::vector<int>::const_iterator& a_r_it,
						const std::vector<int>::const_iterator& b_l_it, const size_t chunk_size);
		void insertTwo(std::vector<int>::const_iterator& a_l_it, const std::vector<int>::const_iterator& b_l_it, const size_t chunk_size);
		void insertThree(const std::vector<int>::const_iterator& a_mid_it, const std::vector<int>::const_iterator& b_l_it, const size_t chunk_size);

	public:
		FJVector(std::vector<int>& in_arr);
		explicit	FJVector(const FJVector &copy);
		FJVector&	operator=(const FJVector &copy);
		~FJVector();

		void sort(void);
};
