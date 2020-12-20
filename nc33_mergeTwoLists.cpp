#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int value):val(value), next(nullptr) {}
};

class Solution {
public:
    /**
     * 
     * @param l1 ListNode类 
     * @param l2 ListNode类 
     * @return ListNode类
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        ListNode *lead = head;
        while (l1 || l2)
        {
            ListNode *node;
            if (l1 && l2)
            {
                if (l1->val <= l2->val)
                {
                    node = l1;
                    l1 = l1->next;
                }
                else
                {
                    node = l2;
                    l2 = l2->next;
                }
            }
            else if (l1)
            {
                node = l1;
                l1 = l1->next;
            }
            else 
            {
                node = l2;
                l2 = l2->next;
            }
            if (lead == nullptr)
            {
                lead = node;
                head = lead;
            }
            else
            {
                lead->next = node;
                lead = node;
            }
        }
        return head;
    }
};

int main(int argc, const char* argv[]) {

    return 0;
}