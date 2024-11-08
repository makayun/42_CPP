#include <iostream>
#include <vector>

int main() {
	std::vector<int> v;
	v.reserve(10);

	std::cout << *(v.end() - 1) << std::endl;
}
