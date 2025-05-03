#include <iostream>
#include <vector>
#include "MirrorTreePosition.h"
#include "MirrorTreeStructure.h"

using namespace std;


int main() {

    vector<int> tree = {
             3,
         2,        5,
      0,   3,   4,   11,
     0,0, 0,0, 2,0, 0,14
    };

    MirrorTreePosition mtp = MirrorTreePosition(tree);
    MirrorTreeStructure mts = MirrorTreeStructure(tree);

    mtp.mirror(0);
    mts.mirror(0, 0);

    cout << "Original tree" << endl;
    for (size_t i = 0; i < tree.size(); i++) {
        cout << tree[i] << ',';
    }

    cout << endl << endl << "Inverted tree using position" << endl;
    mtp.print();

    cout << endl << endl << "Inverted tree using structure" << endl;
    mts.print();

    return 0;
}
