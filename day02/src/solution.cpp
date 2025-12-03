#include <cmath>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>

struct Solution {
	uint64_t partOne;
	uint64_t partTwo;

	Solution(uint64_t a, uint64_t b) { partOne = a; partTwo = b; }

	void print() {
		std::cout << "Part 1: " << std::to_string(partOne) << std::endl;
		std::cout << "Part 2: " << std::to_string(partTwo) << std::endl;
	}
};

class GiftShopDatabase {
public:
	bool isInvalidId(uint64_t);
private:
	int getNumDigits(uint64_t);
};

bool GiftShopDatabase::isInvalidId(uint64_t num) {
	int numDigits = getNumDigits(num);
	if (numDigits & 1) return false; 
	std::cout << "The number of digits in " << std::to_string(num) << " is " << std::to_string(numDigits) << std::endl;
	return false;
}

int GiftShopDatabase::getNumDigits(uint64_t num) {
	return (int)log10((double)num) + 1;
}

Solution solve(std::vector<std::string> input) {
	GiftShopDatabase db;
	std::stringstream ranges{input[0]};
	size_t hyphen;
	uint64_t start, end;
	std::string range;
	Solution solution(0, 0);

	while (std::getline(ranges, range, ',')) {
		std::cout << "Range is " << range << std::endl;
		hyphen = range.find('-');
		start = std::stoi(range.substr(0, hyphen));
		end = std::stoi(range.substr(hyphen + 1));
	std::cout << "Start is " << std::to_string(start) << " and end is " << std::to_string(end) << std::endl;
		 for (uint64_t i = start; i <= end; i++) {
			if (db.isInvalidId(i)) solution.partOne++;
		}
	}


	return solution;
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
