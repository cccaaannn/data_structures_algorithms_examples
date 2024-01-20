#pragma once

#include <iostream>
#include <queue>
#include <set>
#include <map>

template <typename T, typename U> std::ostream& operator<< (std::ostream& out, std::map<T, U>& map) {

    out << "{ ";
    int index = 0;
    for (const auto& node : map) {

        out << node.first << ":" << node.second;

        if (index != map.size() - 1) {
            out << ", ";
        }

        index++;
    }
    out << " }";

    return out;
}
