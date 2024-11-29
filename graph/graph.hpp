#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include "edge.hpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

typedef unordered_set<Edge *> EdgeSet;
typedef unordered_set<string> NodeSet;

class Graph
{
private:
    unordered_map<string, EdgeSet> adjacencyList;
    NodeSet foundNodes;

    bool NodeExists(string node);
    EdgeSet *InitializeSearch(string startNode, string node);
    Edge *FindNodeDFSHelper(string nodeToFind, string currentNode, Edge *lastEdge);

public:
    Graph();

    void InsertNode(string node);
    void InsertEdge(string startNode, string edge, int weight);

    void PrintEdges(string node);
    void PrintGraphEdges(void);

    Edge *FindNodeDFS(string startNode, string node);
    Edge *FindNodeBFS(string startNode, string node);

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

EdgeSet *Graph::InitializeSearch(string startNode, string node)
{
    if (node == startNode)
    {
        cout << "Tried to start a search for node " << node << " starting with that node!" << endl;
        return nullptr;
    }

    if (!this->NodeExists(startNode))
    {
        cout << "Start node not found in graph: " << startNode << endl;
        return nullptr;
    }

    if (!this->NodeExists(node))
    {
        cout << "End node not found in graph: " << node << endl;
        return nullptr;
    }

    EdgeSet *startNodeEdges = &this->adjacencyList.at(node);

    if (startNodeEdges->empty())
    {
        cout << "Tried to start a search for node " << node << " from a node with no edges: " << startNode << endl;
        return nullptr;
    }

    foundNodes.clear();

    return startNodeEdges;
}

Edge *Graph::FindNodeDFSHelper(string nodeToFind, string currentNode, Edge *lastEdge)
{

    if (nodeToFind == currentNode)
    {
        return lastEdge;
    }

    this->foundNodes.insert(currentNode);
    Edge *foundEdge = nullptr;

    for (auto &&edge : this->adjacencyList.at(currentNode))
    {
        if (this->foundNodes.count(edge->label) != 0)
        {
            cout << "Skipping edge from " << currentNode << " to " << edge->label << endl;
            continue;
        }

        cout << "Exploring edge from " << currentNode << " to " << edge->label << endl;
        foundEdge = this->FindNodeDFSHelper(nodeToFind, edge->label, edge);

        if (foundEdge != nullptr)
        {
            return foundEdge;
        }
    }

    cout << "Backtracking from node " << currentNode << endl;

    return nullptr;
}

Edge *Graph::FindNodeDFS(string startNode, string node)
{
    EdgeSet *startNodeEdges = this->InitializeSearch(startNode, node);

    if (startNodeEdges == nullptr)
    {
        return nullptr;
    }

    Edge *arbitraryEdge = *(startNodeEdges->begin());

    return this->FindNodeDFSHelper(startNode, node, arbitraryEdge);
}

Edge *Graph::FindNodeBFS(string startNode, string node)
{
    if (this->InitializeSearch(startNode, node) == nullptr)
    {
        return nullptr;
    }

    string currentNode;
    EdgeSet currentEdges;
    NodeSet exploredNodes;
    queue<string> nodeQueue;

    nodeQueue.push(startNode);
    exploredNodes.insert(startNode);

    while (!nodeQueue.empty())
    {
        currentNode = nodeQueue.front();
        nodeQueue.pop();

        cout << "Exploring edges from node " << currentNode << endl;
        currentEdges = this->adjacencyList.at(currentNode);

        for (auto &&edge : currentEdges)
        {
            if (exploredNodes.count(edge->label) != 0)
            {
                cout << "Skipping edge from " << currentNode << " to " << edge->label << endl;
                continue;
            }

            if (edge->label == node)
            {
                return edge;
            }

            cout << "Found node " << edge->label << endl;
            nodeQueue.push(edge->label);
            exploredNodes.insert(edge->label);
        }

        cout << "Done exploring node " << currentNode << endl;
    }

    return nullptr;
}

void Graph::DeleteEdge(string startNode, string endNode)
{
    if (!this->NodeExists(startNode) || !this->NodeExists(endNode))
    {
        return;
    }

    Edge *edgeToDelete = nullptr;

    for (auto &&edge : this->adjacencyList.at(startNode))
    {
        if (edge->label == endNode)
        {
            edgeToDelete = edge;
            break;
        }
    }

    if (edgeToDelete != nullptr)
    {
        this->adjacencyList.at(startNode).erase(edgeToDelete);
        delete edgeToDelete;
    }
}

void Graph::DeleteNode(string node)
{
    if (!this->NodeExists(node))
    {
        return;
    }

    for (auto &&edge : this->adjacencyList.at(node))
    {
        delete edge;
    }

    this->adjacencyList.erase(node);

    for (auto &&startNodePair : this->adjacencyList)
    {
        EdgeSet edgesToDelete;

        for (auto &&edge : startNodePair.second)
        {
            if (edge->label == node)
            {
                edgesToDelete.insert(edge);
                delete edge;
            }
        }

        for (auto &&edge : edgesToDelete)
        {
            this->adjacencyList.at(startNodePair.first).erase(edge);
        }
    }
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