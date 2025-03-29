#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "MazeSolver.h"


class MazeVisualizer {
private:
    static const char WALL = 'X';
    static const char PATH = 'O';
    static const char MARKER = 'W';

    const MazeSolver& solver;

    /**
     * @brief Prints maze with markers using a given path
     *
     * @param p path to print
     */
    void print_maze(const std::vector<node>& p) {
        // Copy maze
        std::vector<std::vector<char>> maze_copy;
        maze_copy.assign(solver.get_maze().begin(), solver.get_maze().end());

        // Mark paths
        for (const auto n : p)
            maze_copy[n.x][n.y] = MARKER;

        // Print
        for (const auto mx : maze_copy) {
            for (auto my : mx) {
                std::cout << my << " ";
            }
            std::cout << std::endl;
        }
    }

    /**
     * @brief Prints raw maze
     *
     */
    void print_maze() {
        for (const auto mx : solver.get_maze()) {
            for (const auto my : mx) {
                std::cout << my << " ";
            }
            std::cout << std::endl;
        }
    }

    /**
     * @brief Prints solution path
     *
     */
    void print_solution_path() {
        const auto& solution = solver.get_solution();

        for (size_t i = 0; i < solution.size(); i++) {
            std::cout << "(" << solution[i].x << "," << solution[i].y << ")";
            if (i + 1 < solution.size()) {
                std::cout << "->";
            }
        }
        std::cout << std::endl;
    }

public:
    MazeVisualizer(MazeSolver& solver) : solver(solver) {}

    void visualize() {
        std::cout << "Maze" << std::endl;
        print_maze();
        std::cout << std::endl;

        std::cout << "Solution maze" << std::endl;
        print_maze(solver.get_solution());
        std::cout << std::endl;

        std::cout << "Visited maze" << std::endl;
        print_maze(solver.get_visited());
        std::cout << std::endl;

        std::cout << "Solution path" << std::endl;
        print_solution_path();
        std::cout << std::endl;
    }
};
