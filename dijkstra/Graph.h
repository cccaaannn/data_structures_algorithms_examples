#pragma once

#include <string>
#include <limits.h>
#include <set>
#include <map>

class Graph {
private:
    std::map<std::string, std::map<std::string, int>> nodes;

    template <typename T> bool setContains(std::set<T> s, std::string value) {
        return s.find(value) != s.end();
    }

    /*
        * Finds the next node to visit by finding the smallest distance from the start node that has not been visited.
        * @param distances: map of distances from start node
        * @param visited: set of visited nodes
        * @return next node to visit
    */
    std::string findNextNode(std::map<std::string, int> distances, std::set<std::string> visited) {

        std::string smallestNode;
        int smallestDistance = INT_MAX;

        for (const auto& node : distances) {
            if (!setContains(visited, node.first) && node.second < smallestDistance) {
                smallestNode = node.first;
                smallestDistance = node.second;
            }
        }

        return smallestNode;
    }

public:
    Graph() {}

    void addEdge(const std::string& from, const std::string& to, int weight) {
        nodes[from][to] = weight;
    }

    std::map<std::string, int> dijkstra(const std::string& startNode) {
        std::map<std::string, int> distances;
        std::set<std::string> visited;

        // Initialize distances
        for (const auto& node : nodes) {
            distances[node.first] = INT_MAX;
        }

        // Set start node distance to 0
        distances[startNode] = 0;

        while (visited.size() != nodes.size()) {

            // Find next node to visit
            std::string currentNode = findNextNode(distances, visited);

            // Mark node as visited
            visited.insert(currentNode);

            // Update distances
            for (const auto& neighbor : nodes[currentNode]) {
                if (distances[currentNode] + neighbor.second < distances[neighbor.first]) {
                    distances[neighbor.first] = distances[currentNode] + neighbor.second;
                }
            }
        }

        return distances;
    }

};
