#include <iostream>
#include <vector>
#include <cmath>

class MirrorTreeStructure {
private:
    std::vector<int> tree;

    void swap(int index1, int index2) {
        int temp = tree[index1];
        tree[index1] = tree[index2];
        tree[index2] = temp;
    }

    int get_left(int index) {
        int left = (index * 2) + 1;
        if (left >= tree.size()) return -1;
        return left;
    }

    int get_right(int index) {
        int right = (index * 2) + 2;
        if (right >= tree.size()) return -1;
        return right;
    }

public:
    MirrorTreeStructure(const std::vector<int> tree) {
        this->tree.assign(tree.begin(), tree.end());
    }

    /**
     * @brief Mirrors the tree using the indexes of nodes,
     * keeps track of the old index to swap correct values while modifing the array.
     * 
     * @param index index of the node to start mirroring from
     * @param old_index old index of the node to swap with
     */
    void mirror(int index, int old_index) {
        if (index >= tree.size() || old_index >= tree.size()) return;

        int left = get_left(index);
        int right = get_right(index);

        int old_left = get_left(old_index);
        int old_right = get_right(old_index);

        if (left != -1 && old_right != -1) {
            swap(left, old_right);
        }

        if (left != -1 && old_right != -1) {
            mirror(left, old_right);
        }

        if (right != -1 && old_left != -1) {
            mirror(right, old_left);
        }
    }

    void print() {
        for (size_t i = 0; i < tree.size(); i++) {
            std::cout << tree[i] << ',';
        }
    }

};