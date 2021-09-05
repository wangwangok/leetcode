#include <iostream>
#include <vector>
#include "nc_util.hpp"

/*
描述:
给定某二叉树的前序遍历和中序遍历，请重建出该二叉树并返回它的头结点。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建出如下图所示。

提示:
1.0 <= pre.length <= 2000
2.vin.length == pre.length
3.-10000 <= pre[i], vin[i] <= 10000
4.pre 和 vin 均无重复元素
5.vin出现的元素均出现在 pre里
6.只需要返回根结点，系统会自动输出整颗树做答案对比

输入：[1,2,4,7,3,5,6,8],[4,7,2,1,5,3,8,6]
输出：{1,2,3,4,#,5,6,#,7,#,#,8}
*/



using namespace std;

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        size_t pSize = pre.size();
        size_t vSize = vin.size();
        if (pSize <= 0 || vSize <= 0 || pSize != vSize) return nullptr;
        TreeNode *root = subTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
        return root;
    }

private:
    TreeNode* subTree(vector<int>& pre, int pLeft, int pRight,vector<int>& vin, int vLeft, int vRight) {
        if (pLeft > pRight || vLeft > vRight) {
            return nullptr;
        }
        int treeNodeVal = pre[pLeft];
        int i = vLeft;
        for (; i < vRight; ++i) {
            if (vin[i] == treeNodeVal) {
                break;
            }
        }
        if (i > vRight) return nullptr;
        TreeNode *node = new TreeNode(treeNodeVal);
        pLeft = pLeft+1;
        int len = i - vLeft;
        node->left = subTree(pre, pLeft, pLeft+len-1, vin, vLeft, i-1);
        node->right = subTree(pre, pLeft+len, pRight, vin, i+1, vRight);
        return node;
    }
};

