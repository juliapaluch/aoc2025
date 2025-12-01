#include <cstdint>
#include <fstream>
#include <iostream>


uint64_t part1(std::vector<std::string> input) {
	uint64_t solution = 0;
	return solution;
}

uint64_t part2(std::vector<std::string> input) {
	uint64_t solution = 0;
	return solution;
}

int main(int argc, char* argv[]) {
	std::ifstream infile("input/input.txt");
	std::string line;
	std::vector<std::string> input;
	while (std::getline(infile, line)) {
		input.push_back(line);
	}

	std::cout << std::to_string(part1(input)) << std::endl;
	std::cout << std::to_string(part2(input)) << std::endl;

	return 0;
}
