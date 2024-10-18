#include <iostream>
#include <iomanip>
#include <fstream>

#define GRN "\033[1;92m"
#define RED "\033[0;31m"
#define RES "\033[0m"

void drawTrees(std::ostream& out, short width, short trees) {
	int q = width / 2 + 1;

	if (&out == &std::cout)
		out << GRN;
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < trees; j++) {
			out << std::setw(q - i) << std::setfill(' ') << "*";
			out << std::setw(i * 2 + 1) << std::setfill('*') << " ";
			out << std::setw(q - i) << std::setfill(' ') << " ";
		}
		out << std::endl;
	}

	if (&out == &std::cout)
		out << RED;
	for (int k = 0; k < trees; k++) {
		out << std::setw(q) << std::setfill(' ') << "|";
		out << std::setw(q + 1) << std::setfill(' ') << " ";
	}
	if (&out == &std::cout)
		out << RES;
	out << std::endl;
}


int main()
{
	std::ofstream file("trees.txt");
	if (file.is_open()) {
		drawTrees(file, 9, 4);
		file.close();
	}
	else
		std::cerr << "Can't open the file!" << std::endl;

	drawTrees(std::cout, 6, 3);

}
