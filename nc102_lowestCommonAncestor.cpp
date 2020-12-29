#include <iostream>
#include <vector>

using namespace std;

/**
 给定一棵二叉树以及这棵树上的两个节点 o1 和 o2，请找到 o1 和 o2 的最近公共祖先节点。  
 */

struct TreeNode {	
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int v):val(v), left(nullptr), right(nullptr){}
};


class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        if (root == nullptr)
        {
            return 0;
        }
        TreeNode *node = root;
        vector<TreeNode *> stack;
        TreeNode *parent_node = nullptr;
        vector<TreeNode *> right_child_visisted;
        vector<int> finded;
        while (1)
        {
            for(;node;node=node->left)
            {
                int val = node->val;
                stack.push_back(node);
            }
            if (stack.size() <= 0 || finded.size() == 2)
            {
                break;
            }
            TreeNode *top = *(stack.end() - 1);
            stack.pop_back();
            if (parent_node != nullptr && (top->left == parent_node || top->right == parent_node))
            {
                parent_node = top;
            }
            if (top->val == o1 || top->val == o2)
            {
                if (finded.size() == 0) {
                    parent_node = top;
                    finded.push_back(top->val);
                } else if (finded[0] != top->val) {
                    finded.push_back(top->val);
                    break;
                }
            }
            if (top->right == nullptr)
            {    
                node = top->right;
                continue;
            }
            if (right_child_visisted.size() > 0 && top->right == *(right_child_visisted.end() - 1))
            {
                node = nullptr;
                right_child_visisted.pop_back();
            }
            else
            {
                node = top->right;
                right_child_visisted.push_back(top->right);
                stack.push_back(top);
            }
        }
        if (finded.size() == 2 && parent_node != nullptr)
        {
            return parent_node->val;
        }
        return 0;
    }
};

int main(int argc, const char **argv) {
    TreeNode *node0 = new TreeNode(0);
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node8 = new TreeNode(8);
    TreeNode *node9 = new TreeNode(9);
    TreeNode *node10 = new TreeNode(10);
    TreeNode *node11 = new TreeNode(11);
    TreeNode *node12 = new TreeNode(12);
    TreeNode *node13 = new TreeNode(13);

    node12->left = node3;
    node12->right = node13;
    node3->left = node5;
    node3->right = node1;
    node5->left=node6;
    node5->right=node2;
    node1->left=node0;
    node1->right=node8;
    node2->left=node7;
    node2->right=node4;
    Solution s;
    int result = s.lowestCommonAncestor(node12, 7, 13);
    cout<<result<<endl;
    return 0;
} 