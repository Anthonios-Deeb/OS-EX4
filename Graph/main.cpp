#include <iostream>
#include <unistd.h>
#include "vectorList_graph.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    int opt;
    int numEdges = 0, numVertices = 0;
    unsigned int seed = 0;

    // Define the options
    while ((opt = getopt(argc, argv, "e:v:s:")) != -1)
    {
        switch (opt)
        {
        case 'e':
            numEdges = atoi(optarg);
            break;
        case 'v':
            numVertices = atoi(optarg);
            break;
        case 's':
            seed = static_cast<unsigned int>(atoi(optarg));
            break;
        default:
            cerr << "Usage: " << argv[0] << " -e numEdges -v numVertices -s seed" << endl;
            exit(EXIT_FAILURE);
        }
    }

    // Check if all options were provided
    if (numEdges == 0 || numVertices == 0 || seed == 0)
    {
        cerr << "Usage: " << argv[0] << " -e numEdges -v numVertices -s seed" << endl;
        exit(EXIT_FAILURE);
    }

    // Check if the number of edges is valid
    int maxEdges = numVertices * (numVertices - 1) / 2;
    if (numEdges > maxEdges)
    {
        cerr << "Error: Number of edges cannot exceed " << maxEdges << " for " << numVertices << " vertices." << endl;
        exit(EXIT_FAILURE);
    }

    // Create a graph
    Graph graph(numVertices, numEdges, seed);

    // Print the graph
    graph.printGraph();

    // Check if the graph is Eulerian
    int resutl = graph.isEulerian();
    if (resutl == 0)
    {
        cout << "The graph is not Eulerian." << endl;
    }
    else if (resutl == 1)
    {
        cout << "The graph has Eulerian path." << endl;
    }
    else if (resutl == 2)
    {
        cout << "The graph has Eulerian cycle." << endl;
    }

    return 0;
}
