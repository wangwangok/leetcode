#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int value):val(value), left(nullptr), right(nullptr){}
};

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector <TreeNode *> queue;
        TreeNode *node = root;
        vector<vector<int>> result;
        queue.push_back(node);
        while (queue.size() > 0)
        {
            vector<int> nodeValue;
            vector<TreeNode *>::iterator min_itr = queue.begin();
            vector<TreeNode *>::iterator max_itr = queue.end();
            vector<TreeNode *>::iterator itr = min_itr;
            vector<TreeNode *> levelQueue;
            while (itr != max_itr)
            {
                if ((*itr)->left != nullptr)
                {
                    levelQueue.push_back((*itr)->left);
                }
                if ((*itr)->right != nullptr)
                {
                    levelQueue.push_back((*itr)->right);
                }
                nodeValue.push_back((*itr)->val);
                itr++;
            }
            queue.clear();
            queue = levelQueue;
            result.push_back(nodeValue);
        }
        return result;
    }
};

int main(int argc, const char* argv[]) {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    node1->left=node2;
    Solution s;
    vector<vector<int>>result = s.levelOrder(node1);
    cout<<"Run"<<endl;
    return 0;
}