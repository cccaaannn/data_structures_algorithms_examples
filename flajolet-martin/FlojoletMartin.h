#pragma once

#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>

class FlojoletMartin {
private:
    int hashFn(int x) const {
        return (1 * x + 6) % 32;
    }

    std::string toBinaryStr(int x) const {
        return std::bitset<8>(x).to_string();
    }

    int countRightmostZeroBits(const std::string& str) const {
        int count = 0;
        for (int i = str.size() - 1; i >= 0; i--) {
            if (str[i] == '0') {
                count++;
            }
            else {
                break;
            }
        }
        return count;
    }

public:
    int estimate(const std::vector<int>& dataList) const {
        int max = 0;

        // Iterate over items
        for (const auto& item : dataList) {
            // Hash the item
            int hashed = hashFn(item);

            // Convert item to binary
            std::string binStr = toBinaryStr(hashed);

            // Find rightmost 0 count
            int rightmostZeroCount = countRightmostZeroBits(binStr);

            // Set the max
            max = std::max(max, rightmostZeroCount);
        }

        return pow(2, max);
    }
};
