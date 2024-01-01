#include <iostream>
#include <string>
#include <vector>
#include "BloomFilter.h"

using namespace std;

int main() {

    vector<string> strList = {
        "test1",
        "test1",
        "test2",
        "test3",
        "test4",
        "test1",
        "test2",
    };

    BloomFilter bloomFilter;

    for (int i = 0; i < strList.size(); i++) {
        bool exists = bloomFilter.exists(strList[i]);

        if (exists) {
            cout << "Probably exists   - " << strList[i] << endl;
        }
        else {
            bloomFilter.insert(strList[i]);
            cout << "Not exists insert - " << strList[i] << endl;
        }
    }

    return 0;
}