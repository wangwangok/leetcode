#include <iostream>

using namespace std;

/**
 * 输入两个链表，找出它们的第一个公共结点。（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）
 */

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int l1_length = 0, l2_length = 0;
        for (ListNode *l1_lead = pHead1; l1_lead; l1_lead = l1_lead->next) l1_length++;
        for (ListNode *l2_lead = pHead2; l2_lead; l2_lead = l2_lead->next) l2_length++;
        ListNode *result = nullptr;
        if (l1_length == l2_length)
        {
            result = pHead2;
        }
        else if (l1_length > l2_length)
        {
            ListNode *lead = pHead1;
            ListNode *lead2 = pHead2;
            for (int gap = l1_length - l2_length; gap > 0; gap--) lead = lead->next;
            while (lead && lead2)
            {
                if (lead == lead2) break;
                lead = lead->next;
                lead2 = lead2->next;
            }
            result = lead;
        }
        else
        {
            ListNode *lead = pHead1;
            ListNode *lead2 = pHead2;
            for (int gap = l2_length - l1_length; gap > 0; gap--) lead2 = lead2->next;
            while (lead && lead2)
            {
                if (lead == lead2) break;
                lead = lead->next;
                lead2 = lead2->next;
            }
            result = lead2;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
     ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    node2->next=node1;
    ListNode *node3 = new ListNode(3);
    node3->next=node2;
    ListNode *node4 = new ListNode(4);
    node4->next=node3;

    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(6);
    node6->next = node1;
    ListNode *node7 = new ListNode(7);
    node7->next = node6;
    ListNode *node8 = new ListNode(8);
    node8->next = node7;

    Solution s;
    ListNode *result = s.FindFirstCommonNode(node4, node7);
    cout<<result->val<<endl;
    return 0;
}