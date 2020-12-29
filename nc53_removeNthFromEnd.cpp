#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // write code here
        if (head == nullptr) return nullptr;
        ListNode *lead = head;
        ListNode *tail = nullptr, *mid = nullptr;
        while (lead)
        {
            if (n - 1 > 0) 
            {
                n--;
            }
            else if (n - 1 == 0)
            {
                if (mid == nullptr)
                {
                    mid = head;
                }
                else 
                {
                    tail = mid;
                    mid = mid->next;
                }
            }
            lead = lead->next;
        }
        if (mid == head)
        {
            head = head->next;
        }
        else if (tail && mid)
        {
            tail->next = mid->next;
            mid->next = nullptr;
        }
        return head;
    }
};

int main(int argc, const char *argv[]) {
    Solution s;
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    node2->next=node1;
    ListNode *node3 = new ListNode(3);
    node3->next=node2;
    ListNode *node4 = new ListNode(4);
    node4->next=node3;
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(6);
    node5->next=node4;
    node6->next=node5;
    ListNode *result = s.removeNthFromEnd(node6, 6);
    while (result)
    {
        cout<<result->val<<endl;
        result = result->next;
    }
    return 0;
}