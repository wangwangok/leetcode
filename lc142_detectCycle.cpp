#include <iostream>
#include "nc_util.hpp"
#include <vector>

/**
 * 
 * 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 */

using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode *fast = head, *slow = head;
        while(fast != nullptr && slow != nullptr) {
            ListNode *fastNext = fast->next;
            if (fastNext) fast = fastNext->next;
            if (slow) slow = slow->next;
            if (fast == slow) break;
        }
        if (fast == nullptr || slow == nullptr) return nullptr;
        ListNode *inNode = nullptr;
        if (fast == slow) {
            inNode = fast;
        }
        if (inNode == nullptr) return nullptr;
        /*
        c = m + n;
        p + xc + n = 2 * (p + yc + n);
        p = xc + n - 2yc - 2n;
        p = xc - 2yc - n;
        p = xc - 2yc - c + m
        p = c (x-2y-1) + m
        */
       ListNode *result = nullptr, *lead = head;
       while (lead != inNode && lead && inNode) {
           lead = lead->next;
           inNode = inNode->next;
       }
       if (lead == inNode) result = lead;
       return result;
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    vector<int> list = {3,2,0,-4};
    ListNode *root = ListNode::linklist(list);
    ListNode *lead = root;
    ListNode *in = root->next;
    while (lead)
    {
        lead = lead->next;
        if (lead->next == nullptr) break;
    }
    lead->next = in;
    cout<<s.detectCycle(root)->val<<endl;
    
    return 0;
}