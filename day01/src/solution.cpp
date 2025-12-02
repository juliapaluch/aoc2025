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


class Lock {
public:
	int64_t dial;
	int64_t password;

	Lock() { dial = 50; password = 0; }

	void turn(std::string rotation) {
		char direction = rotation.at(0);
		int amount = std::stoi(rotation.substr(1));
		switch (direction) {
			case 'L': dial -= amount; break;
			case 'R': dial += amount; break;
			default: std::cout << "wtf" << std::endl;
		}
		normalize();
		std::cout << "The dial is now at " << std::to_string(dial) << std::endl;
		std::cout << "The password is now at " << std::to_string(password) << std::endl;
		if (dial == 0) password++;
	}

private:	
	void normalize() { 
		dial %= 100;
		if (dial < 0) dial += 100;
	}
};

Solution solve(std::vector<std::string> input) {
	Lock lock;
	for (std::string rotation : input) {
		lock.turn(rotation);
	}
	return Solution(lock.password, 0);
}

int main(int argc, char* argv[]) {
	std::ifstream infile("input/input.txt");
	std::string line;
	std::vector<std::string> input;
	while (std::getline(infile, line)) {
		input.push_back(line);
	}

	Solution solution = solve(input);
	solution.print();

	return 0;
}
