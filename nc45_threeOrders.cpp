#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value):val(value), left(nullptr), right(nullptr){}
};

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */

    /// 中序
    vector<int> inorder(TreeNode *root) {
        vector<int> result;
        vector<TreeNode *> stack;
        TreeNode *node = root;
        while (1)
        {   
            for (;node; node=node->left)
            {
                stack.push_back(node);
            }
            if (stack.size() <= 0)
            {
                break;
            }
            node = *(stack.end()-1);
            stack.pop_back(); /// 移除当前栈顶元素，因此移除之后的栈顶为当前元素的父结点；
            result.push_back(node->val);
            /// 如果当前结点有右子节点，则依次将右子节点的所有左结点加入栈中
            /// 如果当前结点没有右子节点，那么当前node为nullptr，那么下一轮的for循环将不会执行，因此直接执行获取下一个栈顶元素，并执行pop操作。
            node = node->right;
        }
        return result;
    }

    /// 先序
    vector<int> preorder(TreeNode *root) {
        vector<int> result;
        vector<TreeNode *> stack;
        TreeNode *node = root;
        while (1)
        {
            for (;node; node=node->left)
            {
                result.push_back(node->val);
                if (node->right)
                {
                    stack.push_back(node->right);
                }
            }
            if (stack.size() <= 0)
            {
                break;
            }
            node=*(stack.end()-1);
            stack.pop_back();
        }
        return result;
    }

    /// 后序
    vector<int> postorder(TreeNode *root) {
        vector<int> result;
        vector<TreeNode *> stack;
        TreeNode *node = root;
        vector<TreeNode *>rightVisited;
        while (1)
        {
            for (;node; node=node->left)
            {
                stack.push_back(node);
            }
            if (stack.size() <= 0)
            {
                break;
            }
            node = *(stack.end()-1);
            stack.pop_back();
            if (node->right == nullptr) /// 叶子结点
            {
                result.push_back(node->val);
                node=node->right;
                continue;
                
            }
            
            if (rightVisited.size() > 0 && node->right == *(rightVisited.end()-1))
            {
                result.push_back(node->val);
                rightVisited.pop_back();
                node = nullptr;
            }
            else
            {
                stack.push_back(node);
                node=node->right;
                rightVisited.push_back(node);
            }
        }
        return result;
    } 

    vector<vector<int> > threeOrders(TreeNode* root) {
        // write code here
        vector<vector<int>> result;
        if (root == nullptr)
        {
            return result;
        }
        vector<int> in = inorder(root);
        vector<int> pre = preorder(root);
        vector<int> post = postorder(root);
        result.insert(result.end(), {in, pre, post});
        return result;
    }
};

int main(int argc, const char* argv[]) {
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
    node1->left=node2;
    node2->left=node3;
    node2->right=node4;
    node3->left=node5;
    node3->right=node6;
    node4->right=node7;
    node6->right=node8;
    node8->left=node9;
    Solution s;
    vector<vector<int>> result = s.threeOrders(node1);
    cout<<"[";
    for(vector<vector<int>>::iterator itr = result.begin(); itr != result.end(); itr++)
    {
        vector<int> temp = *itr;
        cout<<"[";
        for(vector<int>::iterator jtr = temp.begin(); jtr != temp.end(); jtr++)
        {
            cout<<*jtr<<", ";
        }
        cout<<"], ";
    }
    cout<<"]";
    
    return 0;
}