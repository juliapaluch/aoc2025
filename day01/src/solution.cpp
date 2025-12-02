#include <cstdint>
#include <fstream>
#include <iostream>

class Lock {
public:
	int dial;
	int password;

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
		if (dial == 0) password++;
	}

private:	
	void normalize() { 
		dial %= 100;
		if (dial < 0) dial += 100;
	}
};

uint64_t part1(std::vector<std::string> input) {
	Lock lock;
	for (std::string rotation : input) {
		lock.turn(rotation);
	}
	return lock.password;
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
