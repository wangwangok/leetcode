#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
};

class Solution {
public:
    ///
    TreeNode *getNext(const TreeNode *top, const TreeNode *node) {
        if (node == nullptr)
        {
            return nullptr;
        }
        TreeNode *next;
        /// 1. 当前结点存在右子结点，那么在中序遍历中，下一个结点即当前的结点右子树中最左子节点；
        for(TreeNode *c_node = node->right; c_node ; )
        {
            if (c_node->left)
            {
                c_node = c_node->left;
                next = c_node;
            }
        }
        if (next)
        {
            return next;
        }
        /// 2. 当前结点不存在右子结点，那么如果当前结点是其父节点的左子结点，那么当前结点的下一个结点就是父结点；
        /// 3. 当前结点不存在右子结点，并且当前结点不是其父结点的左子结点，那么我们就以当前结点会起点，依次寻找其父节点，知道某一个父节点A是其某一个结点（B）的左子树
        if (node->parent == nullptr)
        {
            return nullptr; /// 如果当前结点无父节点和右子结点，那么当前结点就是最后一个结点。无后续结点，返回nullptr
        }
        TreeNode *parent = node->parent;
        const TreeNode *c_node = node;
        while (parent != nullptr && c_node == parent->right)
        {
            c_node = parent;
            parent = parent->parent;
        }
        /// 如果是第三种情况，即当前结点不是父节点的右子节点，那么该结点就是父节点的左子节点。不会进入循环，直接执行这一步
        next = parent; 
        return next;
    }
};

int main(int argc, const char* argv[]) {

    return 0;
}