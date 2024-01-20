#include <iostream>
#include "MapUtils.h"
#include "Graph.h"

using namespace std;

int main() {

    Graph graph;

    graph.addEdge("A", "B", 6);
    graph.addEdge("A", "C", 2);
    graph.addEdge("B", "A", 6);
    graph.addEdge("B", "D", 1);
    graph.addEdge("C", "A", 2);
    graph.addEdge("C", "D", 3);
    graph.addEdge("D", "B", 1);
    graph.addEdge("D", "C", 3);
    graph.addEdge("D", "E", 1);
    graph.addEdge("E", "D", 1);
    graph.addEdge("E", "F", 4);
    graph.addEdge("F", "E", 4);

    auto distances = graph.dijkstra("A");

    cout << distances << endl;

    return 0;
}