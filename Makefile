compile:
	g++ main.cpp personer.cpp person.cpp -o main.out

run: compile
	./main.out
