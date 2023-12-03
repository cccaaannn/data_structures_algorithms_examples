#include <iostream>
#include "Graph.h"

using namespace std;

int main() {

    Graph graph(11);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(0, 4);
    graph.addEdge(1, 5);
    graph.addEdge(1, 6);
    graph.addEdge(2, 7);
    graph.addEdge(3, 8);
    graph.addEdge(4, 9);
    graph.addEdge(4, 10);

    cout << endl << "--- Graph ---" << endl;

    cout << graph << endl;

    cout << endl << "--- BFS ---" << endl;

    graph.BFS(0);

    cout << endl << "--- DFS ---" << endl;

    graph.DFS(0);

    return 0;
}