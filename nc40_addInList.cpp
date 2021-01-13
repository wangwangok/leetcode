#include <iostream>

using namespace std;

/**
 * 假设链表中每一个节点的值都在 0 - 9 之间，那么链表整体就可以代表一个整数。
 * 给定两个这种链表，请生成代表两个整数相加值的结果链表。
 * 例如：链表 1 为 9->3->7，链表 2 为 6->3，最后生成新的结果链表为 1->0->0->0。
 * -> [9,3,7],[6,3]
 * -> {1,0,0,0}
 */

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int value):val(value), next(nullptr) {}
    ListNode():val(0), next(nullptr) {}
};

class Solution {
public:
    /**
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        if (head1 == nullptr) return head1;
        if (head2 == nullptr) return head2;
        reverseLink(&head1);
        reverseLink(&head2);
        ListNode *head = nullptr, *curptr = nullptr;
        int carry_in = 0;
        for (ListNode *node1 = head1, *node2 = head2; node1 || node2 || carry_in > 0;)
        {
            int value = (node1 ? node1->val : 0) + (node2 ? node2->val : 0) + carry_in;
            carry_in = value / 10;
            value %= 10;
            ListNode *node = new ListNode(value);
            if (head == nullptr) 
            {
                head = node;
                curptr = head;
            }
            else
            {
                curptr->next = node;
                curptr = node;
            }
            if (node1) node1 = node1->next;
            if (node2) node2 = node2->next;
        }
        reverseLink(&head);
        return head;
    }

    void reverseLink(ListNode** head) {
        if (head==nullptr) return;
        ListNode *lead = *head;
        ListNode *mid = nullptr, *tail = nullptr;
        while (lead)
        {
            mid = lead;
            lead = lead->next;
            mid->next = tail;
            tail = mid;
        }
        if (mid) *head = mid;
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
    node6->next = node5;
    ListNode *node7 = new ListNode(7);
    node7->next = node6;
    ListNode *node8 = new ListNode(8);
    node8->next = node7;

    ListNode *result = s.addInList(node4, node7);
    while (result)
    {
        cout<<result->val<<", ";
        result = result->next;
    }
    cout<<endl;
    return 0;
}