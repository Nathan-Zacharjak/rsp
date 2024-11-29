all: compile run

compile: tree.cpp main.cpp
	g++ -O2 -Wall -std=c++23 -o main.exe tree.cpp main.cpp 

run: main.exe
	./main.exe