#include "nc_util.hpp"

void TreeNode::buildTree(std::vector<int> &nodes, TreeNode **root) {
    using namespace std;
    if (nodes.size() <= 0) {
        if (root) {
            *root = nullptr;
        }
    }
    TreeNode *head = nullptr;
    vector<TreeNode *> nodePtrs;
    auto copyValue = [&nodePtrs](TreeNode *ptr, int index) {
        if (index >= nodePtrs.size()) {}
        auto node = nodePtrs[index];
        if (node == nullptr) {
            return;
        }
        if (node->val == -1) {
            node = nullptr;
        }
        if (index % 2 == 0) {
            ptr->right = node;
        } else {
            ptr->left = node;
        }
    };
    for (int i = 0; i < nodes.size(); i++) {
        TreeNode *node = new TreeNode(nodes[i]);
        nodePtrs.push_back(node);
    }
    for (int i = 0; i < nodePtrs.size(); i++) {
        TreeNode *node = nodePtrs[i];
        if (head == nullptr) {
            head = node;
        }
        int l_i = 2 * i + 1;
        copyValue(node, l_i);
        int r_i = l_i + 1;
        copyValue(node, r_i);
        if (root) {
            *root = head;
        }
    }
}

ListNode *ListNode::linklist(std::vector<int> &vals) {
    ListNode *head = nullptr, *lead = nullptr;
    if (vals.size() <= 0)
        return head;
    for (std::vector<int>::iterator itr = vals.begin(); itr != vals.end();
         ++itr) {
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
    if (node == nullptr)
        return;
    cout << endl;
    cout << "[";
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "]" << endl;
}