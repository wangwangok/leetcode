#include <iostream>

/**
 * 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，返回null。
 */

/**
 * 输入分为2段，第一段是入环前的链表部分，第二段是链表环的部分，后台将这2个会组装成一个有环或者无环单链表
 * 返回链表的环的入口结点即可。而我们后台程序会打印这个节点
 */


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

using namespace std;

class Solution {
    ListNode * isCycle(ListNode *pHead) {
        if (pHead == nullptr)
        {
            return nullptr;
        }
        ListNode *fast = pHead;
        ListNode *slow = pHead;
        do {
            if (slow == nullptr || fast == nullptr)
            {
                return nullptr;
            }
            if (fast->next != nullptr)
            {
                fast = fast->next->next;
            }
            slow = slow->next;
        } while (slow != fast);
        return fast;
    }
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode *pt = isCycle(pHead);
        if (pt == nullptr) return nullptr;
        ListNode *sp = pHead;
        ListNode *cp = pt;
        while (sp != nullptr && cp != nullptr)
        {
            if (sp == cp) {
                return sp;
            }
            sp = sp->next;
            cp = cp->next;
        }
        return nullptr;
    }
};

int main(int argc, const char *argv[]) {
    Solution s;
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    node1->next = node2;
    ListNode *node3 = new ListNode(3);
    node2->next=node3;
    ListNode *node4 = new ListNode(4);
    node3->next=node4;
    ListNode *node5 = new ListNode(5);
    node4->next=node5;
    ListNode *node6 = new ListNode(6);
    node5->next=node3;

    node6->next = node6;

    ListNode *node7 = new ListNode(7);

    cout << s.EntryNodeOfLoop(node6)->val << endl;
    return 0;
}