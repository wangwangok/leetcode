#include <iostream>
#include <vector>
#include <stack>

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 * 
 * 给定一个二叉树和一个值sum，请找出所有的根节点到叶子节点的节点值之和等于sum 的路径，
 */

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @param sum int整型
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        // write code here
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> path;
        preOrder(root, res, path, sum, 0);
        return res;
    }
 
    void preOrder(TreeNode* root, vector<vector<int> > &res, vector<int> path, int sum, int current) {
        if (!root) return;
        current = current + root->val;
        path.push_back(root->val);
        if (!root->left && !root->right && sum == current) res.push_back(path);
        if (root->left) preOrder(root->left, res, path, sum ,current);
        if (root->right) preOrder(root->right, res, path, sum ,current);
    }
};

/*
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        if (root == nullptr)
        {
            return result;
        }
        int total = 0;
        TreeNode *node = root;
        TreeNode *pNode = nullptr;
        vector<int> res_list;
        while (node) {
            pNode = node;
            int val = node->val;
            total += val;
            res_list.push_back(val);
            if (node->right != nullptr) {
                vector<vector<int> > temp = pathSum(node->right, sum - total);
                if (temp.size() > 0) {
                    vector<int> rs(res_list.begin(), res_list.end());
                    for (vector<vector<int> >::iterator itr = temp.begin(); itr != temp.end(); ++itr) {
                        rs.insert(rs.end(), itr->begin(), itr->end());
                        result.push_back(rs);
                    }
                }
            }
            node = node->left;
        }
        if (total == sum && (pNode != nullptr && pNode->right == nullptr && pNode->left == nullptr))
        {
            result.push_back(res_list);
        }
        return result;
    }
};
*/

int main(int argc, const char *argv[]) {
    Solution s;

 /*    
    //case 1, sum = 22
    TreeNode *root = new TreeNode();
    root->val = 5;

    TreeNode *node1 = new TreeNode();
    node1->val = 4;
    root->left = node1;

    TreeNode *node2 = new TreeNode();
    node2->val = 8;
    root->right = node2;

    TreeNode *node3 = new TreeNode();
    node3->val = 1;
    node1->left = node3;

    TreeNode *node4 = new TreeNode();
    node4->val = 11;
    node1->right = node4;

    TreeNode *node5 = new TreeNode();
    node5->val = 9;
    node2->right = node5;

    TreeNode *node6 = new TreeNode();
    node6->val = 2;
    node4->left = node6;

    TreeNode *node7 = new TreeNode();
    node7->val = 7;
    node4->right = node7;
*/

/* 
    //cae 2: sum = -2
    TreeNode *root = new TreeNode();
    root->val = -2;

    TreeNode *node1 = new TreeNode();
    node1->val = -3;
    root->right = node1;
*/

    //cae 3: sum = 3
    TreeNode *root = new TreeNode();
    root->val = 1;

    TreeNode *node1 = new TreeNode();
    node1->val = 2;
    root->left = node1;


    vector<vector<int> > result = s.pathSum(root, 3);
    cout<<"size: "<<result.size()<<endl;
    for (vector<vector<int> >::iterator itr = result.begin(); itr != result.end(); ++itr) {
        cout<<endl;
        for (vector<int>::iterator sitr = itr->begin(); sitr != itr->end(); ++sitr) {
            cout<< *sitr << " ";
        }
    }
    return 0;
}