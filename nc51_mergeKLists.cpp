#include <iostream>
#include <vector>

using namespace std;

/**
 * 合并 k 个已排序的链表并将其作为一个已排序的链表返回。分析并描述其复杂度。 
 * 输入：[{1,2,3},{4,5,6,7}]
 * 输出：{1,2,3,4,5,6,7}
 */

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &list) {
        return mergeSubLists(list, 0, list.size() - 1);
    }

    ListNode *mergeSubLists(vector<ListNode *> &list, size_t left, size_t right) {
        size_t size = right - left + 1;
        if ( size == 0)
        {
            return nullptr;
        }
        if (size == 1) 
        {
            return list[left];
        }
        int mid = left + size / 2;
        return merge2list(mergeSubLists(list, left, mid-1), mergeSubLists(list, mid, right));
    }

    ListNode *merge2list(ListNode *node1, ListNode *node2) {
        if (node1 == node2) return node1;
        ListNode *resultNode = new ListNode(0);
        ListNode *lead = resultNode;
        do {
            if (node1 && node2)
            {
                if (node1->val <= node2->val) {
                    lead->next = node1;    
                    lead = node1;
                    node1 = node1->next;
                } else {
                    lead->next = node2;
                    lead = node2;
                    node2 = node2->next;
                }
            } 
            else if (node1)
            {
                lead->next = node1;    
                lead = node1;
                node1 = node1->next;
            }
            else 
            {
                lead->next = node2;
                lead = node2;
                node2 = node2->next;
            }
        } while (node1 || node2);
        return resultNode->next;
    }
};

int main(int argc, const char *argv[]) {
    Solution s;
    vector<ListNode *>value;
    
    ListNode *node4 = new ListNode(4);
    ListNode *node6 = new ListNode(6);
    ListNode *node9 = new ListNode(9);
    ListNode *node10 = new ListNode(10);
    ListNode *node20 = new ListNode(20);
    node4->next = node6;
    node6->next = node9;
    node9->next = node10;
    node10->next = node20;

    ListNode *node2 = new ListNode(2);
    ListNode *node5 = new ListNode(5);
    ListNode *node7 = new ListNode(7);
    ListNode *node8 = new ListNode(8);
    ListNode *node11 = new ListNode(11);
    ListNode *node12 = new ListNode(12);
    ListNode *node13 = new ListNode(13);
    node2->next = node5;
    node5->next = node7;
    node7->next = node8;
    node8->next = node11;
    node11->next = node12;
    node12->next = node13;

    ListNode *node1 = new ListNode(1);
    ListNode *node3 = new ListNode(3);
    ListNode *node14 = new ListNode(14);
    ListNode *node15 = new ListNode(15);
    ListNode *node18 = new ListNode(18);
    ListNode *node22 = new ListNode(22);
    node1->next = node3;
    node3->next = node14;
    node14->next = node15;
    node15->next = node18;
    node18->next = node22;

    value.push_back(node4);
    value.push_back(node2);
    value.push_back(node1);

    ListNode *result = s.mergeKLists(value);
    // ListNode *result = s.merge2list(node4, node2);
    cout<<"[";
    while (result)
    {
        cout<<result->val<<", ";
        result = result->next;
    }
    cout<<"]"<<endl;
    return 0;
}