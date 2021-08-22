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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr) return pHead2;
        if (pHead2 == nullptr) return pHead1;
        ListNode *lead = nullptr;
        ListNode *head = nullptr;
        ListNode *l1 = pHead1;
        ListNode *l2 = pHead2;
        while (l1 != nullptr && l2 != nullptr) {
            ListNode *temp = nullptr;
            if (l1->val <= l2->val) {
                temp = l1;
                l1 = l1->next;
            } else {
                temp = l2;
                l2 = l2->next;
            }
            if (lead != nullptr) {
                lead->next = temp;
            }
            lead = temp;
            if (head == nullptr) head = lead;
        }
        if (l1 == nullptr) lead->next = l2;
        else lead->next = l1;
        return head;
    }
};

int main(int argc, const char* argv[]) {

    return 0;
}