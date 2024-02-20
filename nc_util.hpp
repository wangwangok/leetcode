#ifndef NC_UTIL_HPP
#define NC_UTIL_HPP

#include <iostream>
#include <vector>
#include <string>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
    TreeNode() {
    }
    /**
    * 如果需要传入空指针，传入-1即可
    */
    static void buildTree(std::vector<int>& nodes, TreeNode **root);
};

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    static ListNode *linklist(std::vector<int>& vals);
    static void printlist(ListNode *node);
};


#endif