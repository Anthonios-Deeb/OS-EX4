#ifndef VECTORLIST_GRAPH_HPP
#define VECTORLIST_GRAPH_HPP
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Graph
{
public:
    Graph(int n, int m, unsigned int seed); // Random graph

    // Eulerian circuit
    int isEulerian();   // Method to check if this graph is Eulerian or not
    bool isConnected(); // Method to check if all non-zero degree vertices are connected

    // getters
    vector<list<int>> getEdgeList(); // Get the edge list
    vector<list<int>> getGraph();    // Get the adjacency list

    // prints
    void printGraph();
    void printEdgeList();

    bool addEdge(int u, int v);
    bool removeEdge(int u, int v);

private:
    vector<list<int>> graph;
    vector<list<int>> eulerGraph;
    vector<list<int>> scc;
    vector<list<int>> edgeList;
    
    // Eulerian circuit helper functions
    void DFSUtil(int v, vector<bool> &visited); // Function to do DFS starting from v. Used in isConnected();
};

#endif // VECTORLIST_GRAPH_HPP