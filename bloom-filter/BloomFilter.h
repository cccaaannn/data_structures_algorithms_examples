#pragma once

#include <iostream>
#include "HashHelper.h"

class BloomFilter {
private:
    int size;
    bool* bitarray;

    bool lookup(std::string str) {
        int hashedStr1 = HashHelper::hashFn1(str, size);
        int hashedStr2 = HashHelper::hashFn2(str, size);
        int hashedStr3 = HashHelper::hashFn3(str, size);
        int hashedStr4 = HashHelper::hashFn4(str, size);

        if (
            bitarray[hashedStr1] &&
            bitarray[hashedStr2] &&
            bitarray[hashedStr3] &&
            bitarray[hashedStr4]
            ) {
            return true;
        }
        else {
            return false;
        }
    }

    void _insert(std::string str) {
        int hashedStr1 = HashHelper::hashFn1(str, size);
        int hashedStr2 = HashHelper::hashFn2(str, size);
        int hashedStr3 = HashHelper::hashFn3(str, size);
        int hashedStr4 = HashHelper::hashFn4(str, size);

        bitarray[hashedStr1] = true;
        bitarray[hashedStr2] = true;
        bitarray[hashedStr3] = true;
        bitarray[hashedStr4] = true;
    }

public:

    BloomFilter(const int size) {
        BloomFilter::size = size;
        BloomFilter::bitarray = new bool[size];
    }

    BloomFilter() :BloomFilter(100) {}

    void insert(std::string str) {
        _insert(str);
    }

    bool exists(std::string str) {
        return lookup(str);
    }

};
