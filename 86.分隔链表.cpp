/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */
#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// @lc code=start
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *lead = nullptr;
        ListNode *prev = head;
        ListNode *current = nullptr;

        while(prev) {
            if (prev->val >= x)
            {
                lead = prev;
                prev = prev->next;
                continue;
            }
            if (prev == head) {
                current = prev;
                lead = prev;
                prev = prev->next;
                continue;
            }
            ListNode *node = prev->next;
            if (current == nullptr) 
            {
                prev->next = head;
                current = prev;
                head = current;
            }
            else
            {
                if (current->next == prev)
                {
                    current = prev;
                    lead=prev;
                    prev=prev->next;
                    continue;
                }
                
                prev->next = current->next;
                current->next = prev;   
                current = prev;
            }
            lead->next = node;
            prev = lead->next;
        }
        return head;
    }
};
// @lc code=end

int main(int argc, const char* argv[]) {
    ListNode *front;
    ListNode *head;
    size_t size = 7;
    // 1,4,5,3,2,5,2
    vector<int> nums{1,4,5,3,2,5,2};
    for(int i = 0;i < size;i++)
    {
        ListNode *node = new ListNode(nums[i]);
        if (head == nullptr)
        {
            head = node;
            front = node;
        }
        else
        {
            front->next = node;
            front = node;
        }
    }
    Solution s;
    head = s.partition(head,4);
    ListNode *lead = head;
    while (lead)
    {
        cout<<lead->val<<endl;
        lead = lead->next;
    }
    
    return 0;
}
