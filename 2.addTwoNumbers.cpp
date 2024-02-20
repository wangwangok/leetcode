#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode();
        ListNode *temp = result, *preview = nullptr;
        int carryin = 0;
        ListNode *l1node = l1, *l2node = l2;
        for (;l1node && l2node; l1node = l1node ->next, l2node = l2node -> next) {
            int rs = l1node->val + l2node->val + carryin;
            carryin = rs / 10;
            temp->val = rs % 10;
            ListNode *node = new ListNode();
            temp->next = node;
            preview = temp;
            temp = node;
        }
        
        for (
            ListNode *lastNode = l1node ? l1node : (l2node ? l2node : nullptr);
            lastNode; 
            lastNode = lastNode->next
            ) {
            int rs = lastNode->val + carryin;
            carryin = rs / 10;
            temp->val = rs % 10;
            ListNode *node = new ListNode();
            temp->next = node;
            preview = temp;
            temp = node;
        }
        if (carryin > 0) {
            temp->val = carryin;
            temp->next = nullptr;
        } else if (preview){
            preview->next = nullptr;
            temp = nullptr;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
