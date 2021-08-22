#include "nc_util.hpp"
#include <vector>

using namespace std;

/*
给定一个二叉树，返回该二叉树的之字形层序遍历，（第一层从左向右，下一层从右向左，一直这样交替）
输入：{1,2,3,#,#,4,5}
返回值：[[1],[3,2],[4,5]]
*/


class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        if (pRoot == nullptr) return {};
        vector<TreeNode *> c_stack;
        vector<TreeNode *> n_stack;
        c_stack.push_back(pRoot);
        bool l2r = true;
        vector<vector<int> > result;
        vector<int> layer;
        while (c_stack.size() > 0 || n_stack.size() > 0)
        {
            TreeNode *node = *(c_stack.end() - 1);
            TreeNode *left = node->left;
            TreeNode *right = node->right;
            if (node == nullptr) goto done;
            layer.push_back(node->val);
            if (l2r) {
                if (left != nullptr) n_stack.push_back(left);
                if (right != nullptr) n_stack.push_back(right);
            } else {
                if (right != nullptr) n_stack.push_back(right);
                if (left != nullptr) n_stack.push_back(left);
            }
            done:
            c_stack.pop_back();
            if (c_stack.size() <= 0) {
                c_stack.swap(n_stack);
                result.push_back(layer);
                layer.erase(layer.begin(), layer.end());
                l2r = !l2r;
            }
        }
        if (layer.size() > 0) 
        {
            result.push_back(layer);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {

    vector<string> nodes = {"1","2","3","4","5"};
    //{"8","6","10","5","7","9","11"};
    //{"1","2","3","#","#","4","5"};
    TreeNode *node = TreeNode::tree(nodes);
    Solution s;
    vector<vector<int> > result = s.Print(node);

    for (vector<vector<int> >::iterator itr = result.begin(); itr != result.end(); ++itr) {
        vector<int> list = *itr;
        cout<<"[";
        for (vector<int>::iterator jtr = list.begin(); jtr != list.end(); ++jtr) {
            cout<<*jtr<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}