#include <iostream>
#include "ScalarConverter.hpp"



int main(int argc, char **argv) {
	if (argc != 2)
		std::cout << "Usage: \"" << argv[0] << " <some literal in its most common form>\"" << std::endl;
	else {
		std::string input(argv[1]);
		ScalarConverter::convert(input);
	}
}
