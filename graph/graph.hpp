#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include "end_node.hpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Graph
{
private:
    unordered_map<string, unordered_set<EndNode *>> adjacencyList;

public:
    Graph();

    void InsertNode(string node);
    void InsertEdge(string startNode, string endNode, int weight);

    void PrintEdges(string node);
    void PrintAllEdges(void);

    EndNode *FindNodeDFS(string node);
    EndNode *FindNodeBFS(string node);

    void DeleteEdge(string startNode, string endNode);
    void DeleteNode(string deleteNode);

    ~Graph();
};

Graph::Graph()
{
}

void Graph::InsertNode(string node)
{
    unordered_set<EndNode *> emptySet;
    this->adjacencyList[node] = emptySet;
}

void Graph::PrintEdges(string node)
{
    unordered_set<EndNode *> edges = this->adjacencyList.at(node);

    cout << "Outward edges of: " << node << " ->" << endl;

    for (auto edge : edges)
    {
        cout << edge->label << " Weight: " << edge->weight << endl;
    }
}

Graph::~Graph()
{
}

#endif