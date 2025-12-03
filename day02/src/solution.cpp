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
	bool isInvalidIdPartOne(uint64_t);
	bool isInvalidIdPartTwo(uint64_t);
private:
	int getNumDigits(uint64_t);
	std::vector<int> getMultiples(int);
	bool isInvalidMultiple(uint64_t, int, int);
};

bool GiftShopDatabase::isInvalidIdPartOne(uint64_t num) {
	int numDigits = getNumDigits(num);
	if (numDigits & 1) return false; 
	int midPoint = numDigits/2;
	int firstHalf = num / std::pow(10, midPoint);
	int secondHalf = num % (uint64_t)std::pow(10, midPoint);
	return firstHalf == secondHalf;
}

bool GiftShopDatabase::isInvalidIdPartTwo(uint64_t num) {
	int numDigits = getNumDigits(num);
	if (numDigits == 1) return false; 
	for (int multiple : getMultiples(numDigits)) {
		if (isInvalidMultiple(num, multiple, numDigits)) return true;
	}
	return false;
}

int GiftShopDatabase::getNumDigits(uint64_t num) {
	return (int)log10((double)num) + 1;
}

std::vector<int> GiftShopDatabase::getMultiples(int numDigits) {
	std::vector<int> multiples;
	multiples.push_back(numDigits);
	for (int i = 2; i <= numDigits / 2; i++) {
		if (numDigits % i == 0) multiples.push_back(i);
	}
	return multiples;
}

bool GiftShopDatabase::isInvalidMultiple(uint64_t num, int multiple, int numDigits) {
	int windowSize = numDigits / multiple;
	int lastWindow = num / (uint64_t)std::pow(10, numDigits - windowSize);
	int window = 0;

	for (int i = 1; i < multiple; i++) {
		window = (num % (uint64_t)std::pow(10, numDigits - i*windowSize)) / std::pow(10, numDigits - (i+1)*windowSize);
		if (window == lastWindow) lastWindow = window;
		else return false;
	}
	return true;
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
			if (db.isInvalidIdPartOne(i)) {
				solution.partOne += i;
			}
			if (db.isInvalidIdPartTwo(i)) {
				solution.partTwo += i;
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
