#include "nc_util.hpp"

class Solution {
  private:
    int maxValue(TreeNode *node, int v) {
        if (node == nullptr) {
            return v;
        }
        int lv = v, rv = v;
        lv = maxValue(node->left, v + 1);
        rv = maxValue(node->right, v + 1);
        return lv > rv ? lv : rv;
    }

  public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return maxValue(root, 0);
    }
};

int main(int argc, char const *argv[]) {
    using namespace std;
    vector<int> nums = {3, 9, 20, -1, -1, 15, 7};
    TreeNode *root = nullptr;
    TreeNode::buildTree(nums, &root);
    cout << "complete" << endl;
    Solution s;
    int result = s.maxDepth(root);
    cout << result << endl;
    return 0;
}
