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
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        ListNode *lead = head;
        ListNode *mid = nullptr, *tail = nullptr, *left = nullptr, *right = nullptr;
        while (1)
        {
            int i = k;
            ListNode *temp = lead;
            for (; i > 0 && temp; i--)
            {
                temp = temp->next;
            }
            ListNode *ori = lead;
            if (i <= 0)
            { /// 满足个数
                while (lead != temp)
                {
                    mid = lead;
                    lead = lead->next;
                    mid->next = tail;
                    tail = mid;
                }
                if (left)
                {
                    left->next = mid;
                }
                left = ori;
                if (right == nullptr)
                {
                    right = mid;
                }
            }
            else 
            { /// 不满足个数
                if (left)
                {
                    left->next=lead;
                }
                else
                {
                    right = head;
                }
                break;
            }
        }
        return right;
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
    ListNode *node7 = new ListNode(7);
    ListNode *node8 = new ListNode(8);
    node5->next=node4;
    node6->next=node5;
    node7->next=node6;
    node8->next=node7;
    ListNode *nd = s.reverseKGroup(node8, 6);
    while (nd)
    {
        cout<<nd->val<<endl;
        nd = nd->next;
    }
    return 0;
}