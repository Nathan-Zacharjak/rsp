all: compile run

compile: node.cpp main.cpp
	g++ -O2 -Wall -std=c++23 -o main.exe node.cpp main.cpp

run: main.exe
	./main.exe