#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)    
        {
            return false;
        }
        ListNode *lead = head->next;
        ListNode *tail = head;
        while (lead && tail)
        {
            if (lead == tail)
            {
                return true;
            }
            
            if (lead->next)
            {
                lead=lead->next->next;
            }
            else
            {
                lead=nullptr;
            }
            tail = tail->next;
        }
        return false;
    }
};

int main(int argc, const char* argv[]) {
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

    node1->next=node4;
    bool result = s.hasCycle(node4);
    cout<<result<<endl;
    return 0;
}