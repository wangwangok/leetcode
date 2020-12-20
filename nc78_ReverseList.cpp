#include <iostream>

using namespace std;
struct ListNode
{
    int val;
    struct ListNode *next;
    
    ListNode(int x):val(x), next(nullptr){}
};

class Solution {
    public :
    ListNode* ReverseList(ListNode *pHead) {
        if (pHead == nullptr)
        {
            return nullptr;
        }
        ListNode *lead = pHead;
        ListNode *mid  = pHead;
        ListNode *tail = nullptr;
        while (mid)
        {
            lead = lead->next;
            mid->next = tail;
            tail = mid;
            mid = lead;
        }
        return tail;
    }
};


int main(int argc, const char * argv[]) {
   ListNode *node5 = new ListNode(5);
   ListNode *node4 = new ListNode(4);
   ListNode *node3 = new ListNode(3);
   ListNode *node2 = new ListNode(2);
   ListNode *node1 = new ListNode(1);
   node1->next = node2;
   node2->next = node3;
   node3->next = node4;
   node4->next = node5; 
   Solution S;
   ListNode*result = S.ReverseList(node1);
   while (result)
   {
      cout<<result->val<<endl;
      result=result->next; 
   }
   
    return 0;
}