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

ListNode *ListNode::linklist(std::vector<int>& vals) {
    ListNode *head = nullptr, *lead = nullptr;
    if (vals.size() <= 0) return head;
    for (std::vector<int>::iterator itr = vals.begin(); itr != vals.end(); ++itr) {
        ListNode *node = new ListNode(*itr);
        if (head == nullptr) {
            head = node;
            lead = head;
        } else {
            lead->next = node;
            lead = node;
        }
    }
    return head;
}

void ListNode::printlist(ListNode *node) {
    using namespace std;
    if (node == nullptr) return;
    cout<<endl;
    cout<<"[";
    while (node)
    {
        cout<<node->val<<" ";
        node=node->next;
    }
    cout<<"]"<<endl;
}