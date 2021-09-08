#include <iostream>
#include "nc_util.hpp"

/**
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 *      你可以设计一个只使用常数额外空间的算法来解决此问题吗？
 *      你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 * 
 * 输入：head = [1,2,3,4,5], k = 2
 * 输出：[2,1,4,3,5]
 * 
 * 输入：head = [1,2,3,4,5], k = 3
 * 输出：[3,2,1,4,5]
 * 
 * 输入：head = [1,2,3,4,5], k = 1
 * 输出：[1,2,3,4,5]
 */

using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k<1) return head;
        if (head == nullptr) return nullptr;
        ListNode *resultPtr = nullptr;
        ListNode *lead = head, *endPtr = nullptr;
        while (lead)
        {
            ListNode *node = lead;
            int i = 1;
            while (i < k)
            {
                if (node->next == nullptr) {
                    break;
                }
                node = node->next;
                i++;
            }
            
            if (i == k)
            {
                ListNode *mid = nullptr, *tail = nullptr;
                ListNode *temp_head = lead;
                while (mid != node) {
                    mid = lead;
                    lead = lead->next;
                    mid->next = tail;
                    tail = mid;
                }
                if (resultPtr == nullptr && mid) {
                    resultPtr = mid;
                }
                if (endPtr) endPtr->next = mid;
                endPtr = temp_head;
            } 
            else
            {
                if (resultPtr == nullptr && lead) resultPtr = lead;
                if (endPtr) endPtr->next = lead;
                while (lead && i >= 0) {
                    endPtr = lead;
                    lead = lead->next;
                    i--;
                } 
            }
        }
        return resultPtr;
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    vector<int> vals = {
        1,2,3,4,5,6,7,8,9,10,11,12,13,14
    };
    int k = 
    3
    ;
    ListNode *head = ListNode::linklist(vals);
    ListNode *result = s.reverseKGroup(head,k);
    ListNode::printlist(result);
    return 0;
}