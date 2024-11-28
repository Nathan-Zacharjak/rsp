#include "graph.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    Graph graph;

    graph.InsertNode("A");
    // graph.InsertNode("B");
    // graph.InsertNode("C");
    // graph.InsertNode("D");

    // // graph.InsertEdge("A", "B", 1);
    // // graph.InsertEdge("A", "C", 2);
    // // graph.InsertEdge("B", "C", 10);
    // // graph.InsertEdge("B", "D", 1);
    // // graph.InsertEdge("C", "D", 2);

    graph.PrintEdges("A");

    return 0;
}