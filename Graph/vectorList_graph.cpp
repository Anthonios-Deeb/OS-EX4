#include "vectorList_graph.hpp"

Graph::Graph(int n, int m, unsigned int seed)
{
    graph.resize(n + 1);
    srand(seed);
    for (int i = 0; i < m; i++)
    {
        int u = rand() % n + 1;
        int v = rand() % n + 1;
        if(!addEdge(u, v)){
            i--;
        }
    }
    eulerGraph = graph;
}

vector<list<int>> Graph::getEdgeList()
{
    vector<list<int>> ans;
    for (size_t i = 0; i < this->graph.size(); i++)
    {
        for (auto x : this->graph[i])
        {
            list<int> temp;
            temp.push_back(i);
            temp.push_back(x);
            ans.push_back(temp);
        }
    }
    return ans;
}

void Graph::printGraph()
{
    for (size_t i = 1; i < graph.size(); i++)
    {
        cout << "Vertex " << i << ": ";
        for (auto it = graph[i].begin(); it != graph[i].end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}

void Graph::printEdgeList()
{
    for (size_t i = 0; i < edgeList.size(); i++)
    {
        cout << "Edge " << i + 1 << ": ";
        for (auto it = edgeList[i].begin(); it != edgeList[i].end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}

bool Graph::addEdge(int u, int v)
{
    if (u <= 0 || v <= 0 || u > (int)(this->graph.size() - 1) || v > (int)(this->graph.size() - 1) || u == v)
    {
        cout << "Invalid input. Out of bounds." << endl;
        return false;
    }

    auto itv = find(graph[u].begin(), graph[u].end(), v);
    auto itu = find(graph[v].begin(), graph[v].end(), u);
    if (itv == graph[u].end() && itu == graph[v].end())
    {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    else
    {
        cout << "Invalid input. The edge already exists." << endl;
        return false;
    }

    this->edgeList = getEdgeList();

    return true;
}

bool Graph::removeEdge(int u, int v)
{
    if (u <= 0 || v <= 0 || u > (int)(this->graph.size() - 1) || v > (int)(this->graph.size() - 1) || u == v)
    {
        cout << "Invalid input. Out of bounds." << endl;
        return false;
    }

    auto itv = find(graph[u].begin(), graph[u].end(), v);
    auto itu = find(graph[v].begin(), graph[v].end(), u);
    if (itv != graph[u].end() && itu != graph[v].end())
    {
        graph[u].erase(itv);
        graph[v].erase(itu);
    }
    else
    {
        cout << "Invalid input. The edge does not exist." << endl;
        return false;
    }

    this->edgeList = getEdgeList();
    return true;
}

vector<list<int>> Graph::getGraph()
{
    return this->graph;
}

void Graph::DFSUtil(int v, vector<bool> &visited)
{
    // Mark the current node as visited and print it
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = eulerGraph[v].begin(); i != eulerGraph[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

bool Graph::isConnected()
{
    int size = eulerGraph.size();
    // Mark all the vertices as not visited
    vector<bool> visited(size, false);
    int i;
    for (i = 0; i < size; i++)
        visited[i] = false;

    // Find a vertex with non-zero degree
    for (i = 0; i < size; i++)
        if (eulerGraph[i].size() != 0)
            break;

    // If there are no edges in the graph, return true
    if (i == size)
        return true;

    // Start DFS traversal from a vertex with non-zero degree
    DFSUtil(i, visited);

    // Check if all non-zero degree vertices are visited
    for (i = 0; i < size; i++)
        if (visited[i] == false && eulerGraph[i].size() > 0)
            return false;

    return true;
}

/* The function returns one of the following values
    0 --> If graph is not Eulerian
    1 --> If graph has an Euler path (Semi-Eulerian)
    2 --> If graph has an Euler Circuit (Eulerian)  */
int Graph::isEulerian()
{
    int size = eulerGraph.size();
    // Check if all non-zero degree vertices are connected
    if (isConnected() == false)
        return 0;

    // Count vertices with odd degree
    int odd = 0;
    for (int i = 0; i < size; i++){
        if (eulerGraph[i].size() % 2 == 1)
        {   
            odd++;
        }
    }

    // If count is more than 2, then graph is not Eulerian
    if (odd > 2)
        return 0;

    // If odd count is 2, then semi-eulerian.
    // If odd count is 0, then eulerian
    // Note that odd count can never be 1 for undirected graph
    return (odd) ? 1 : 2;
}