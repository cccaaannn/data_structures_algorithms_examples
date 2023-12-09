#pragma once

#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <bitset>

class FlojoletMartin {
private:
    int hashFn(int x) {
        return (1 * x + 6) % 32;
    }

    std::string toBinaryStr(int x) {
        return std::bitset<8>(x).to_string();
    }

    int countRightmostZeroBits(std::string str) {
        int count = 0;
        for (int i = str.size() - 1; i > 0; i--) {
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

    int estimate(const std::vector<int>& dataList) {

        int max = 0;

        // Iterate over items
        for (int i = 0; i < dataList.size(); i++) {

            // Hash the item
            int hashed = hashFn(dataList[i]);

            // Convert item to binary
            std::string binStr = toBinaryStr(hashed);

            // Find rightmost 0 count
            int rightmostZeroCount = countRightmostZeroBits(binStr);

            // Set the max
            if (rightmostZeroCount > max) {
                max = rightmostZeroCount;
            }

        }

        return pow(2, max);
    }

};
