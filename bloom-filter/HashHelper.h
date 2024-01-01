#pragma once

#include <string>
#include <cmath>

class HashHelper {
public:
    static int hashFn1(std::string s, int arrSize) {
        long long int hash = 0;
        for (int i = 0; i < s.size(); i++) {
            hash = (hash + ((int)s[i]));
            hash = hash % arrSize;
        }
        return hash;
    }

    static int hashFn2(std::string s, int arrSize) {
        long long int hash = 1;
        for (int i = 0; i < s.size(); i++) {
            hash = hash + pow(19, i) * s[i];
            hash = hash % arrSize;
        }
        return hash % arrSize;
    }

    static int hashFn3(std::string s, int arrSize) {
        long long int hash = 7;
        for (int i = 0; i < s.size(); i++) {
            hash = (hash * 31 + s[i]) % arrSize;
        }
        return hash % arrSize;
    }

    static int hashFn4(std::string s, int arrSize) {
        long long int hash = 3;
        int p = 7;
        for (int i = 0; i < s.size(); i++) {
            hash += hash * 7 + s[0] * pow(p, i);
            hash = hash % arrSize;
        }
        return hash;
    }
};
