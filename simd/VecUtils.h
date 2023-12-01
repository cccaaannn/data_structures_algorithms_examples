#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>
#include <iterator>

const int MIN_RAND = 5;
const int MAX_RAND = 20;

template <typename S> std::ostream &operator<<(std::ostream &os, const std::vector<S> &vector) {
    os << "[";
    for (int i = 0; i < vector.size(); ++i) {
        os << vector[i];

        if(i != vector.size()-1) {
            os << ",";
        }
    }
    os << "]";
    return os;
}

template <typename T> std::vector<T> generateRandomVector(int const size, int const seed) {
    std::srand(seed);
    std::vector<T> v(size);
    std::generate(v.begin(), v.end(), [] { return std::rand() % MAX_RAND + MIN_RAND; });
    return v;
}
