#include <iostream>
#include "nc_util.hpp"
#include <unordered_map>

/**
 * 
 * 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
 * 
 * 输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
 * 输出：Intersected at '8'
 * 解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。
        从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。
        在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
*/

using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        unordered_map<ListNode *, int> map;
        ListNode *lead = headA;
        while(lead) {
            map[lead] = lead->val;
            lead = lead->next;
        }
        lead = headB;
        while(lead) {
            if (map.find(lead) != map.end()) {
                return lead;
            }
            lead = lead->next;
        }
        return nullptr;
    }
};

int main(int argc, const char *argv[])  {

    return 0;
}