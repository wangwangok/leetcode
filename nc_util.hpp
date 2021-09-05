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
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    static TreeNode *tree(std::vector<std::string>& nodes);
};

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


#endif