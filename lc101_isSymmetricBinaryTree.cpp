#include <iostream>
#include "nc_util.hpp"

/**
 * 
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 */

using namespace std;

class Solution {

    bool checkBinary(TreeNode *node1, TreeNode *node2) {
        if (node1 == nullptr && node2 == nullptr) return true;
        if (node1 == nullptr || node2 == nullptr) return false;
        return node1->val == node2->val && checkBinary(node1->left, node2->right) && checkBinary(node1->right, node2->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
       if (root == nullptr) return false;
       return checkBinary(root, root);
    }
};

int main(int argc, const char *argv[]) {
    Solution s;
    s.isSymmetric();
    return 0;
}