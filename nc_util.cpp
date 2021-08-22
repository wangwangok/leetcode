#include "nc_util.hpp"

TreeNode* TreeNode::tree(std::vector<std::string>& nodes) {
    using namespace std;
    if (nodes.size() <= 0) return nullptr;
    TreeNode *head = nullptr;
    vector<TreeNode **> temp;
    for (vector<string>::iterator itr = nodes.begin(); itr != nodes.end(); ++itr) {
        string str = *itr;
        if (str.compare("#") == 0) {
            if (head == nullptr) return head;
            if (temp.size() > 0) {
                TreeNode **child = *(temp.begin());
                temp.erase(temp.begin());
                *child = nullptr;
            }
        } else {
            TreeNode *node = nullptr;
            int v = stoi(str);
            if (temp.size() > 0) {
                TreeNode **child = *(temp.begin());
                (*child)->val = v;
                temp.erase(temp.begin());
                node = *child;
            } else {
                node = new TreeNode(v);
            }
            if (head == nullptr) head = node;
            TreeNode *left = new TreeNode(v);
            TreeNode *right = new TreeNode(v);
            node->left = left;
            node->right = right;
            temp.push_back(&(node->left));
            temp.push_back(&(node->right));
        }
    }
    if (temp.size() > 0) {
        for (vector<TreeNode **>::iterator itr = temp.begin(); itr != temp.end(); ++itr) {
            TreeNode **node = *itr;
            *node = nullptr;
        }
    }
    return head;
}