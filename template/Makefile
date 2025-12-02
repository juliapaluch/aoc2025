all: solution

solution: src/*.cpp
	g++ src/*.cpp -o solution
	./solution input/input.txt

test: src/*.cpp
	g++ src/*.cpp -o solution
	./solution input/test_input.txt

clean:
	rm -f *.o solution
