#pragma once

#include <iostream>
#include <vector>
#include <algorithm>


struct node {
    int x;
    int y;

    bool operator==(const node& other) const {
        return x == other.x && y == other.y;
    }
};

class MazeSolver {
private:
    static const char WALL = 'X';
    static const char PATH = 'O';

    std::vector<std::vector<char>> maze = {};
    std::vector<node> visited = {};
    std::vector<node> solution = {};

    /**
     * @brief Returns true if node is a wall or a impossible index
     *
     * @param n node
     */
    bool is_wall(const node n) {
        if (n.x < 0 || n.y < 0) return true;
        if (n.x >= maze.size()) return true;
        if (n.y >= maze[n.x].size()) return true;
        if (maze[n.x][n.y] == WALL) return true;

        return false;
    }

    /**
     * @brief Sets new node as visited and returns true if node is visited before
     *
     * @param n node
     */
    bool is_visited(const node n) {
        for (size_t i = 0; i < visited.size(); i++) {
            if (visited[i] == n) {
                return true;
            }
        }

        visited.push_back(n);
        return false;
    }

    bool solve_recursive(const node start, const node end) {

        if (start == end) {
            return true;
        }

        node t = { start.x - 1, start.y };
        node b = { start.x + 1, start.y };
        node r = { start.x,     start.y + 1 };
        node l = { start.x,     start.y - 1 };


        if (!is_wall(t) && !is_visited(t)) {
            bool solved = solve_recursive(t, end);
            if (solved) {
                solution.push_back(t);
                return true;
            }
        }

        if (!is_wall(b) && !is_visited(b)) {
            bool solved = solve_recursive(b, end);
            if (solved) {
                solution.push_back(b);
                return true;
            }
        }

        if (!is_wall(r) && !is_visited(r)) {
            bool solved = solve_recursive(r, end);
            if (solved) {
                solution.push_back(r);
                return true;
            }
        }

        if (!is_wall(l) && !is_visited(l)) {
            bool solved = solve_recursive(l, end);
            if (solved) {
                solution.push_back(l);
                return true;
            }
        }

        return false;
    }

public:
    MazeSolver(const std::vector<std::vector<char>>& maze) {
        this->maze.assign(maze.begin(), maze.end());
    }

    const std::vector<std::vector<char>>& get_maze() const {
        return maze;
    }

    const std::vector<node>& get_visited() const {
        return visited;
    }

    const std::vector<node>& get_solution() const {
        return solution;
    }

    bool solve(const node start, const node end) {
        if (is_wall(start) || is_wall(end)) {
            std::cout << "Wrong input provided" << std::endl;
            return false;
        }

        // Clear existing state
        visited.clear();
        solution.clear();

        // Solve
        bool result = solve_recursive(start, end);

        // Add inital node to the last position before reverseing
        solution.push_back(start);

        // Reverse the solution path
        std::reverse(solution.begin(), solution.end());

        return result;
    }
};
