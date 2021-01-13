#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

/**
 * 给定一个二叉树，返回该二叉树的之字形层序遍历，（第一层从左向右，下一层从右向左，一直这样交替）
 * 输入:{1,#,2}
 * 输出:[[1],[2]] 
 */

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
     * @return int整型vector<vector<>>
     */
    struct SetNode{
        vector<TreeNode *> list;
        int idx;
        SetNode *next;
        SetNode(int index):idx(index){}
    };

    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        // write code here
        vector<vector<int> >result;
        if (root == nullptr) return result;
        vector<TreeNode *> list1{root};
        vector<TreeNode *> list2;
        SetNode *node0 = new SetNode(0);
        node0->list = list1;
        SetNode *node1 = new SetNode(1);
        node1->list = list2;
        node0->next = node1;
        node1->next = node0;

        SetNode *node = node0;
        while (node->list.size() > 0)
        {
            vector<TreeNode *> temp = {};
            vector<int> values;
            vector<TreeNode *> nodelist = node->list;
            
            for (
                vector<TreeNode *>::iterator begin = nodelist.begin(),
                end = nodelist.end(),
                itr = begin; 
                itr != end; 
                itr++)
            {
                TreeNode *tmp_node = *itr;
                values.push_back(tmp_node->val);
                if (tmp_node->left)
                {
                    temp.push_back(tmp_node->left);
                }
                if (tmp_node->right)
                {
                    temp.push_back(tmp_node->right);
                }
            }
            node->list.clear();
            if (node->idx == 1) reverse(values.begin(), values.end());
            result.push_back(values);
            node = node->next;
            node->list = temp;
        }
        return result;
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    TreeNode *node0 = new TreeNode();
    node0->val = 3;

    TreeNode *node1 = new TreeNode();
    node1->val = 9;

    TreeNode *node2 = new TreeNode();
    node2->val = 20;

    node0->left = node1;
    node0->right = node2;

    TreeNode *node3 = new TreeNode();
    node3->val = 15;

    TreeNode *node4 = new TreeNode();
    node4->val = 7;

    node1->left = node3;
    node1->right = node4;

    TreeNode *node5 = new TreeNode();
    node5->val = 1;

    TreeNode *node6 = new TreeNode();
    node6->val = 2;

    node2->left = node5;
    node2->right = node6;

    TreeNode *node7 = new TreeNode();
    node7->val = 4;

    TreeNode *node8 = new TreeNode();
    node8->val = 5;

    node3->left = node7;
    node3->right = node8;

    TreeNode *node9 = new TreeNode();
    node9->val = 8;

    TreeNode *node10 = new TreeNode();
    node10->val = 10;

    node4->left = node9;
    node4->right = node10;

    TreeNode *node11 = new TreeNode();
    node11->val = 12;

    TreeNode *node12 = new TreeNode();
    node12->val = 13;

    node5->left = node11;
    node5->right = node12;

    TreeNode *node13 = new TreeNode();
    node13->val = 17;

    TreeNode *node14 = new TreeNode();
    node14->val = 22;

    node6->left = node13;
    node6->right = node14;

    vector<vector<int>> result = s.zigzagLevelOrder(node0);

    cout<<"["<<endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout<<"[";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout<<result[i][j]<<", ";
        }
        cout<<"]"<<endl;
    }
    cout<<"]"<<endl;
    return 0;
}