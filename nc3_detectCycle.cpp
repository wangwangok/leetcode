#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /// 返回相遇点，如果不形成环路，那么返回nullptr
    ListNode* isCycle(ListNode *head) {
        ListNode *lead = head, *tail =head;
        ListNode *result = nullptr;
        while (lead && tail)
        {
            if (lead->next)
            {
                lead = lead->next->next;
                tail = tail->next;
            }
            else
            {
                lead = nullptr; 
            }
            if (lead == tail)
            {
                result = lead;
                break;
            }
        }
        return result;
    }

    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode *equal_ptr = isCycle(head);
        if (equal_ptr == nullptr)
        {
            return equal_ptr;
        }
        /*
        |－－－－－x－－－－－－|－－－－－－－－－－m
        ○ → ○ → ○ → ○ → ○ → ○ → ○ → ○ → ○ → ○ |
                          | ↑               ↓ |
                          | ○               ○ |
                          | ↑               ↓ |
                          | ○ ← ○ ← ● ← ○ ← ○ |
                          n －－－－－|－－－－－－
        ●：表示相遇点
        周长为c，快指针在环内跑了p圈，慢指针在环内跑了q圈。快指针的速度是慢指针速度的2倍，那么相同时间，快指针行进的距离是慢指针的两倍：则有如下公式：
        x+m+p*c = 2(x+m+q*c)；
        x+m+p*c = 2x+2m+2*q*c;
        x = c*(p-2q-1)+n
        也就是说起点距离环入口点的距离为c*(p-2q-1)+n。此时在点处放置一个指针ptr1，在相遇点放置一个指针ptr2，它们两个都是一次移动一个结点：
        当ptr1移动c*(p-2q-1)长度时，那么距离环入口为n；同样的对于ptr2来说，移动c*(p-2q-1)距离，也依然在相遇点不变，距离环入口点长度也是n。
        因此我们知道当ptr1==ptr2时，即是环入口点。
        */
       ListNode *ptr1 = head, *ptr2 = equal_ptr;
       ListNode *result = nullptr;
       while (ptr1 && ptr2)
       {
           if (ptr1 == ptr2)
           {
               result = ptr1;
               break;
           }
           ptr1 = ptr1->next;
           ptr2 = ptr2->next;
       }
       return result;
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
    // node1->next=node4;
    ListNode *result = s.detectCycle(node4);
    cout<<result->val<<endl;
    return 0;
}