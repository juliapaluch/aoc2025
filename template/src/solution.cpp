#include <cstdint>
#include <fstream>
#include <iostream>


struct Solution {
	int64_t partOne;
	int64_t partTwo;

	Solution(uint64_t a, uint64_t b) { partOne = a; partTwo = b; }

	void print() {
		std::cout << "Part 1: " << std::to_string(partOne) << std::endl;
		std::cout << "Part 2: " << std::to_string(partTwo) << std::endl;
	}
};

Solution solve(std::vector<std::string> input) {
	return Solution(0, 0);
}

int main(int argc, char* argv[]) {
	std::ifstream infile(argv[1]);
	std::string line;
	std::vector<std::string> input;
	while (std::getline(infile, line)) {
		input.push_back(line);
	}

	Solution solution = solve(input);
	solution.print();

	return 0;
}
