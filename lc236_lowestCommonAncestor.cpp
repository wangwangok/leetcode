#include <iostream>
#include "nc_util.hpp"
#include <unordered_map>

/**
 * 
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * 输出：3
 */

using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr ||  p == nullptr || q == nullptr) return nullptr;
        unordered_map<TreeNode *, TreeNode *> rMaps;
        dfs(root, rMaps);
        vector<TreeNode *>pNodes;
        pNodes.push_back(p);
        for (unordered_map<TreeNode *, TreeNode *>::iterator pItr = rMaps.find(p);pItr != rMaps.end(); pItr = rMaps.find(p)) {
            p = pItr->second;
            pNodes.push_back(p);
        }
        
        vector<TreeNode *>qNodes;
        qNodes.push_back(q);
        for (unordered_map<TreeNode *, TreeNode *>::iterator pItr = rMaps.find(q);pItr != rMaps.end(); pItr = rMaps.find(q)) {
            q = pItr->second;
            qNodes.push_back(q);
        }
        TreeNode *result = nullptr;
        for (int i = pNodes.size() - 1, j = qNodes.size() - 1; i >= 0 && j >= 0; i--, j--) {
            if (pNodes[i] != qNodes[j]) {
                break;
            }
            result = pNodes[i];
        }
        return result;
    }

    void dfs(TreeNode *node, unordered_map<TreeNode *, TreeNode *>& maps) {
        if (node == nullptr) return;
        if (node->left) {
            maps[node->left] = node;
            dfs(node->left, maps);
        }
        if (node->right) {
            maps[node->right] = node;
            dfs(node->right, maps);
        }
    }
};

int main(int argc, const char *argv[]) {

    return 0;
}