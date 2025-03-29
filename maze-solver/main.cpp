#include <iostream>
#include <vector>
#include "MazeSolver.h"
#include "MazeVisualizer.h"

using namespace std;


void maze_problem1() {
    std::vector<std::vector<char>> maze = {
        {'O', 'X', 'O', 'X', 'X' },
        {'O', 'O', 'O', 'X', 'O' },
        {'X', 'X', 'O', 'X', 'O' },
        {'X', 'X', 'O', 'O', 'O' },
        {'X', 'O', 'O', 'X', 'O' }
    };

    node start = { 0, 0 };
    node end = { 4, 4 };

    MazeSolver solver(maze);
    auto result = solver.solve(start, end);

    if (!result) {
        cout << "No solution found" << endl;
        return;
    }

    MazeVisualizer visualizer(solver);
    visualizer.visualize();
}

void maze_problem2() {
    std::vector<std::vector<char>> maze = {
        {'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X', 'O', 'X', 'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X', 'O', 'X', 'X', 'X', 'O', 'X'},
        {'X', 'X', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'X'},
        {'X', 'O', 'O', 'O', 'O', 'X', 'O', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'X'},
        {'X', 'X', 'X', 'O', 'O', 'X', 'X', 'X', 'O', 'X'},
        {'X', 'X', 'X', 'X', 'O', 'X', 'X', 'O', 'O', 'X'},
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X'}
    };

    node start = { 0, 2 };
    node end = { 9, 7 };

    MazeSolver solver(maze);
    auto result = solver.solve(start, end);

    if (!result) {
        cout << "No solution found" << endl;
        return;
    }

    MazeVisualizer visualizer(solver);
    visualizer.visualize();
}

int main() {

    cout << "Maze problem 1" << endl;
    maze_problem1();

    cout << "----------------" << endl << endl;

    cout << "Maze problem 2" << endl;
    maze_problem2();

    return 0;
}