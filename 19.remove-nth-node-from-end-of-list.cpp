/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */
#include <iostream>

using namespace std;

struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
};
 
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;
        ListNode *lead = head;
        ListNode *tail = head;
        int step = n;
        for(; step > 0; step--) 
        {
            if (lead)
            {
                lead = lead->next;
            }
        }
        if (step != 0)
        {
            return head;
        }
        if (tail == head && lead == nullptr)
        {
            ListNode *temp_head = head;
            head = head->next;
            temp_head->next = nullptr;
            return head;
        }
        while (lead->next)
        {
            lead = lead->next;
            tail = tail->next;
        }
        if (tail->next == lead || tail == lead)
        {
            tail->next = nullptr;
            return head;
        }
        else
        {
            ListNode *dest = tail->next->next;
            tail->next = dest;
            return head;
        }
    }
};
// @lc code=end

int main (int argc, const char* argv[]) {
    Solution s;
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    node1->next = node2;
    ListNode *node3 = new ListNode(3);
    node2->next = node3;
    ListNode *node4 = new ListNode(4);
    node3->next = node4;
    ListNode *node5 = new ListNode(5);
    node4->next = node5;
    ListNode *head = s.removeNthFromEnd(node1,6);
    while (head)
    {
        cout<<head->val<<endl;
        head = head->next;
    }
    
    return 0;
}