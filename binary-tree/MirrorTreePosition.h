#include <iostream>
#include <vector>
#include <cmath>

class MirrorTreePosition {
private:
    std::vector<int> tree;

    int depth_from_index(int index) {
        return floor(log2(index + 1)) + 1;
    }

    int find_section_size_from_depth(int depth) {
        return pow(2, depth) - pow(2, depth - 1);
    }

    int find_mirror_index(int index) {
        int depth = depth_from_index(index);
        int section_size = find_section_size_from_depth(depth);
        int prev_section_size_total = pow(2, depth - 1) - 1;

        int section_size_index = section_size - 1;
        int index_on_section = index - prev_section_size_total;
        int mirrored_index_on_section = section_size_index - index_on_section;
        int actual_mirrored_index = mirrored_index_on_section + prev_section_size_total;

        return actual_mirrored_index;
    }

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
    MirrorTreePosition(const std::vector<int> tree) {
        this->tree.assign(tree.begin(), tree.end());
    }

    /**
     * @brief Mirrors the tree using the indexes of nodes, 
     * finds depth and mirrored position using the index.
     * 
     * @param index index of the node to start mirroring from
     */
    void mirror(int index) {
        if (index >= tree.size()) return;

        int left = get_left(index);
        int right = get_right(index);

        int mirror_index = find_mirror_index(left);

        if (left != -1 && right != -1) {
            swap(left, mirror_index);
        }

        if (left != -1) {
            mirror(left);
        }

        if (right != -1) {
            mirror(right);
        }
    }

    void print() {
        for (size_t i = 0; i < tree.size(); i++) {
            std::cout << tree[i] << ',';
        }
    }

};