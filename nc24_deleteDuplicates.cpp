#include <iostream>

using namespace std;

/**
 * 给出一个升序排序的链表，删除链表中的所有重复出现的元素，只保留原链表中只出现一次的元素。
 * 例如：
 * 输入: {1,2,2}
 * 返回值: {1}
 */

struct ListNode {	
    int val;
	struct ListNode *next;
};

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        ListNode *lead = head->next, *mid = head, *tail = nullptr;
        int dupVal = -1;
        head = nullptr;
        while (lead)
        {
            if (mid->val != lead->val)
            {
                if (mid->val != dupVal) {
                    if (tail == nullptr) {
                        head = mid;
                    }
                    tail = mid;
                }
                mid = lead;
                if (tail != nullptr) {
                    tail->next = mid;
                }
            } 
            else
            {
                dupVal = mid->val;
                if (tail != nullptr && tail->next != nullptr) {
                    if (tail->next->val == dupVal) tail->next = nullptr;
                }
            }
            lead = lead->next;
        }
        if (head == nullptr && mid->val != dupVal)
        {
            head = mid;
        }
        
        return head;
    }
};

int main(int argc, const char *argv[]) {
    Solution s;
    ListNode *nd1 = new ListNode();
    nd1->val = 1;

    ListNode *nd11 = new ListNode();
    nd11->val = 1;

    ListNode *nd111 = new ListNode();
    nd111->val = 1;

    ListNode *nd2 = new ListNode();
    nd2->val = 2;

    ListNode *nd3 = new ListNode();
    nd3->val = 3;

    ListNode *nd33 = new ListNode();
    nd33->val = 3;

    ListNode *nd333 = new ListNode();
    nd333->val = 3;

    ListNode *nd4 = new ListNode();
    nd4->val = 3;

    ListNode *nd5 = new ListNode();
    nd5->val = 4;

    ListNode *nd6 = new ListNode();
    nd6->val = 4;

    ListNode *nd7 = new ListNode();
    nd7->val = 5;

    nd1->next = nd2;
    nd2->next = nd3;
    nd3->next = nd4;
    nd4->next = nd5;
    nd5->next = nd6;
    nd6->next = nd7;
    // 1,2,5

    // nd1->next = nd11;
    // nd11->next = nd111;
    // nd111->next = nd2;
    // nd2->next = nd3;
    // 2,3

    // nd1->next = nd11;
    // nd11->next = nd2;
    // nd2->next = nd3;
    // nd3->next = nd33;
    // nd33->next = nd333;
    // 2

    // nd1->next = nd11;
    // nd11->next = nd111;
    // {}

    // nd1->next = nd2;
    /// 1,2

    // nd1->next = nd11;
    // nd11->next = nd2;
    /// 2

    ListNode *head = s.deleteDuplicates(nd1);
    while (head)
    {
        cout<<head->val<<endl;
        head = head->next;
    }
    

    return 0;
}