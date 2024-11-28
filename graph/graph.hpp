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

    bool NodeExists(string node);

public:
    Graph();

    void InsertNode(string node);
    void InsertEdge(string startNode, string endNode, int weight);

    void PrintEdges(string node);
    void PrintGraphEdges(void);

    EndNode *FindNodeDFS(string node);
    EndNode *FindNodeBFS(string node);

    void DeleteEdge(string startNode, string endNode);
    void DeleteNode(string deleteNode);

    ~Graph();
};

bool Graph::NodeExists(string node)
{
    return this->adjacencyList.find(node) != this->adjacencyList.end();
}

Graph::Graph()
{
}

void Graph::InsertNode(string node)
{
    unordered_set<EndNode *> emptySet;
    this->adjacencyList[node] = emptySet;
}

void Graph::InsertEdge(string startNode, string endNode, int weight)
{
    if (!this->NodeExists(startNode))
    {
        this->InsertNode(startNode);
    }

    if (!this->NodeExists(endNode))
    {
        this->InsertNode(endNode);
    }

    this->adjacencyList.at(startNode).insert(new EndNode(endNode, weight));
}

void Graph::PrintEdges(string node)
{
    unordered_set<EndNode *> edges = this->adjacencyList.at(node);

    cout << "Outward edges of: " << node << " ->" << endl;

    for (auto &&edge : edges)
    {
        cout << edge->label << " Weight: " << edge->weight << endl;
    }
}

void Graph::PrintGraphEdges(void)
{
    for (auto &&startNodePair : this->adjacencyList)
    {
        this->PrintEdges(startNodePair.first);
    }
}

Graph::~Graph()
{
    for (auto &&startNodePair : this->adjacencyList)
    {

        for (auto &&endNode : startNodePair.second)
        {
            delete endNode;
        }
    }
}

#endif