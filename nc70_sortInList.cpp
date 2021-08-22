#include <iostream>
#include <vector>

using namespace std;

/**
 * 给定一个无序单链表，实现单链表的排序(按升序排序)。
 * 输入：[1,3,2,4,5]
 * 输出：{1,2,3,4,5}
 */

struct ListNode {	
    int val;
    struct ListNode *next;
};

class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* sortInList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode *lead = head;
        vector<ListNode *> nodes;
        while (lead)
        {
            ListNode *td = lead;
            lead = lead->next;
            td->next = nullptr;
            nodes.push_back(td);
        }
        while (nodes.size() > 1)
        {
            vector<ListNode *> temp;
            for (vector<ListNode *>::iterator itr = nodes.begin(); itr != nodes.end();) {
                vector<ListNode *>::iterator jtr = itr+1;
                if (jtr != nodes.end()) {
                    ListNode *newNode = listMerge(*itr, *jtr);
                    if (newNode != nullptr) temp.push_back(newNode);
                } else {
                    ListNode *newNode = *itr;
                    if (newNode != nullptr) temp.push_back(newNode);
                    break;
                }
                itr = itr + 2;
            }
            if (temp.size() > 0) nodes = temp;
        }
        if (nodes.size() <= 0) return nullptr;
        return nodes[0];
    }

    ListNode *listMerge(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode *head = nullptr, *lead = nullptr;
        while (l1 != nullptr && l2 != nullptr) {
            ListNode *temp = nullptr;
            if (l1->val <= l2->val) {
                temp = l1;
                l1 = l1->next;
            } else {
                temp = l2;
                l2 = l2->next;
            }
            if (lead != nullptr) lead->next = temp;
            if (head == nullptr) head = temp;
            lead = temp;
        }
        if (l1) { lead->next = l1; }
        else if (l2) { lead->next = l2; }
        return head;
    }
};

int main(int argc, const char *argv[]) {
    Solution s;
    ListNode *node1 = new ListNode();
    node1->val = 1;

    ListNode *node2 = new ListNode();
    node2->val = 3;

    ListNode *node3 = new ListNode();
    node3->val = 2;

    ListNode *node4 = new ListNode();
    node4->val = 4;

    ListNode *node5 = new ListNode();
    node5->val = 5;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    ListNode *result = s.sortInList(node1);
    while (result)
    {
        cout<<result->val<<", ";
        result = result->next;
    }
    cout<<endl;
    return 0;
}