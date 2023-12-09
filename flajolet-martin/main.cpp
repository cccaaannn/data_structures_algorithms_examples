#include <iostream>
#include "FlojoletMartin.h"

using namespace std;

int main() {

    vector<int> dataList{ 1,2,3,4,5,6,4,2,5,9,1,6,3,7,1,2,2,4,2,1 };

    FlojoletMartin fm;

    int res = fm.estimate(dataList);

    cout << res << endl;

    return 0;
}
