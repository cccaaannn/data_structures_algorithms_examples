#include <iostream>
#include "SimdAdd.h"
#include "VecUtils.h"

using namespace std;

int main() {

    vector<float> vec1 = generateRandomVector<float>(17, 1);
    vector<float> vec2 = generateRandomVector<float>(17, 2);

    auto sum = simdAdd(vec1, vec2);

    cout << "Vec1: " << vec1 << endl;
    cout << "Vec2: " << vec2 << endl;
    cout << "Sum:  " << sum << endl;

    return 0;
}
