#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include "edge.hpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef unordered_set<Edge *> EdgeSet;

class Graph
{
private:
    unordered_map<string, EdgeSet> adjacencyList;
    unordered_set<string> exploredNodes;

    bool NodeExists(string node);
    Edge *FindNodeDFSHelper(string nodeToFind, string currentNode, Edge *lastEdge);

public:
    Graph();

    void InsertNode(string node);
    void InsertEdge(string startNode, string edge, int weight);

    void PrintEdges(string node);
    void PrintGraphEdges(void);

    Edge *FindNodeDFS(string node, string startNode);
    Edge *FindNodeBFS(string node, string startNode);

    void DeleteEdge(string startNode, string edge);
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
    EdgeSet emptySet;
    this->adjacencyList[node] = emptySet;
}

void Graph::InsertEdge(string startNode, string edge, int weight)
{
    if (!this->NodeExists(startNode))
    {
        this->InsertNode(startNode);
    }

    if (!this->NodeExists(edge))
    {
        this->InsertNode(edge);
    }

    this->adjacencyList.at(startNode).insert(new Edge(edge, weight));
}

void Graph::PrintEdges(string node)
{
    EdgeSet edges = this->adjacencyList.at(node);

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

Edge *Graph::FindNodeDFSHelper(string nodeToFind, string currentNode, Edge *lastEdge)
{

    if (nodeToFind == currentNode)
    {
        return lastEdge;
    }

    this->exploredNodes.insert(currentNode);
    Edge *foundEdge = nullptr;

    for (auto &&edge : this->adjacencyList.at(currentNode))
    {
        string nextNode = edge->label;

        if (this->exploredNodes.count(nextNode) == 0)
        {
            cout << "Exploring edge from " << currentNode << " to " << nextNode << endl;
            foundEdge = this->FindNodeDFSHelper(nodeToFind, nextNode, edge);

            if (foundEdge != nullptr)
            {
                return foundEdge;
            }
        }
        else
        {
            cout << "Skipping edge from " << currentNode << " to " << nextNode << endl;
        }
    }

    cout << "Backtracking from node " << currentNode << endl;

    return nullptr;
}

Edge *Graph::FindNodeDFS(string node, string startNode)
{
    EdgeSet startNodeEdges = this->adjacencyList.at(startNode);

    if (startNodeEdges.empty())
    {
        cout << "Tried to start a DFS for node " << node << " from a node with no edges: " << startNode << endl;
        return nullptr;
    }

    if (node == startNode)
    {
        cout << "Tried to start a DFS for node " << node << " starting with that node!" << endl;
        return nullptr;
    }

    exploredNodes.clear();
    Edge *arbitraryEdge = *(this->adjacencyList.at(startNode).begin());

    return this->FindNodeDFSHelper(node, startNode, arbitraryEdge);
}

Graph::~Graph()
{
    for (auto &&startNodePair : this->adjacencyList)
    {
        for (auto &&edge : startNodePair.second)
        {
            delete edge;
        }
    }
}

#endif