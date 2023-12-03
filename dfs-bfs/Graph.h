#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

class Graph {
private:
    std::vector<std::vector<int>> adjList;
    friend std::ostream& operator<<(std::ostream& os, const Graph& graph);

    void DFSRecursion(int searchNode, std::vector<bool>& visited) {
        // Mark the current node as visited
        visited[searchNode] = true;
        std::cout << "[DFS] - " << searchNode << " " << std::endl;

        // Recur for all the vertices adjacent to the current node
        for (int i = 0; i < adjList[searchNode].size(); i++) {
            if (!visited[adjList[searchNode][i]]) {
                DFSRecursion(adjList[searchNode][i], visited);
            }
        }
    }

public:
    Graph(int size) {
        adjList.resize(size);
    }

    void addEdge(int rootEdge, int newEdge) {
        if (rootEdge < adjList.size()) {
            adjList[rootEdge].push_back(newEdge);
        }
    }

    void print() {
        for (int i = 0; i < adjList.size(); i++) {
            std::cout << i << "->";

            for (int j = 0; j < adjList[i].size(); j++) {
                std::cout << adjList[i][j];
                if (j != adjList[i].size() - 1) {
                    std::cout << ",";
                }
            }

            if (i != adjList.size() - 1) {
                std::cout << std::endl;
            }
        }
    }

    void DFS(int searchNode) {
        // Mark all the vertices as not visited
        std::vector<bool> visited(adjList.size(), false);

        DFSRecursion(searchNode, visited);
    }

    void BFS(int searchNode) {
        // Mark all the vertices as not visited
        std::vector<bool> visited(adjList.size(), false);

        std::deque<int> queue;

        // Mark the current node as visited and enqueue it
        visited[searchNode] = true;
        queue.push_back(searchNode);

        while (queue.size() > 0) {
            // Dequeue the current node from queue
            searchNode = queue[0];
            queue.pop_front();
            std::cout << "[BFS] - " << searchNode << std::endl;

            // For all the adjacent nodes of the current node
            for (auto i = 0; i < adjList[searchNode].size(); i++) {
                auto adjacent = adjList[searchNode][i];

                // If the node is not visited set visited, and enqueue it
                if (!visited[adjacent]) {
                    visited[adjacent] = true;
                    queue.push_back(adjacent);
                }
            }
        }
    }
};

std::ostream& operator<< (std::ostream& out, Graph& graph) {
    graph.print();
    return out;
}
