all: compile run

compile: node.cpp main.cpp
	g++ -O2 -Wall -std=c++23 -o main.out node.cpp main.cpp

run: main.out
	./main.out