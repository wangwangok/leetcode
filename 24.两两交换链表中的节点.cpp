/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */
#include <iostream>
using namespace std;
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *start = head->next;
        ListNode *end = head;
        ListNode *ans = head;
        while (start)
        {
            ListNode *end_next = start->next;
            ListNode *start_next = nullptr;
            start->next = end;
            if (ans == head)
            {
                ans = start;
            }
            if (end_next)
            {
                end->next = end_next;
                start_next = end_next->next;
                if(start_next) end->next = start_next;
            }
            else
            {
                end->next = nullptr;
                break;
            }
            start = start_next;
            end = end_next;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(1);
    
    
    
    ListNode *node2 = new ListNode(2);
    node1->next = node2;
    ListNode *node3 = new ListNode(3);
    node2->next = node3;
    ListNode *node4 = new ListNode(4);
    node3->next = node4;
    ListNode *node5 = new ListNode(5);
    node4->next = node5;
    /*
    ListNode *node6 = new ListNode(6);
    node5->next = node6;
    */

    Solution s;
    ListNode *ans = s.swapPairs(node1);
    while (ans)
    {
        cout<<ans->val<<endl;
        ans = ans->next;
    }
    return 1;
}