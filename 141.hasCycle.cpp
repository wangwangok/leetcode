#include <iostream>
 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        ListNode *fast = head->next, *slow = head;
        while (fast && slow && fast != slow) {
            ListNode *fNext = fast->next;
            if (fNext == nullptr) {
                return false;
            }
            fast = fNext->next;
            slow = slow->next;
        }
        if (fast && slow && fast == slow) {
            return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
