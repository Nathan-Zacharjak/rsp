#include "graph.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    Graph graph;

    graph.InsertEdge("A", "B", 1);
    graph.InsertEdge("B", "A", 1);
    graph.InsertEdge("A", "C", 2);
    graph.InsertEdge("C", "A", 2);
    graph.InsertEdge("B", "C", 10);
    graph.InsertEdge("C", "B", 10);
    graph.InsertEdge("B", "D", 1);
    graph.InsertEdge("D", "B", 1);
    graph.InsertEdge("C", "D", 2);
    graph.InsertEdge("D", "C", 2);
    graph.InsertEdge("D", "E", 1);
    graph.InsertEdge("E", "D", 1);
    graph.InsertEdge("E", "A", 1);

    graph.PrintGraphEdges();

    graph.DeleteEdge("A", "B");

    graph.PrintGraphEdges();

    return 0;
}