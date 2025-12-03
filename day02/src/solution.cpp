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
	int midPoint = numDigits/2;
	int firstHalf = num / std::pow(10, midPoint);
	int secondHalf = num % (uint64_t)std::pow(10, midPoint);
	return firstHalf == secondHalf;
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
		hyphen = range.find('-');
		start = std::stoll(range.substr(0, hyphen));
		end = std::stoll(range.substr(hyphen + 1));
		 for (uint64_t i = start; i <= end; i++) {
			if (db.isInvalidId(i)) {
				solution.partOne += i;
			}
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
