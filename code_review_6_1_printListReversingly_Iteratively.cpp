#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
       int val;
       struct ListNode *next;
       ListNode(int x) : val(x), next(NULL) {
       }
};

class Solution {
public:
    /// stack
    /*
    vector<int> reversePrint(ListNode* head) {
        if (head == nullptr) return {};
        stack<int> _stack;
        for (ListNode *lead = head; lead; lead = lead -> next)
        {
            _stack.push(lead->val);
        }
        vector<int> ans;
        while (_stack.empty() == false)
        {
            int val = _stack.top();
            ans.push_back(val);
            _stack.pop();
        }
        return ans;
    }
    */

   vector<int> reversePrint(ListNode* head) {
        if (head == nullptr)
        {
            return {};
        }

        auto reverselink = [head]() -> ListNode* {
            ListNode *lead = head;
            ListNode *mid, *tail;
            mid = nullptr;
            while (lead)
            {
                tail = mid;
                mid = lead;
                lead = lead->next;
                mid->next = tail;
            }
            return mid;
        };
        head = reverselink();
        vector<int> ans;
        for (ListNode *lead = head; lead; lead = lead -> next)
        {
            ans.push_back(lead->val);
        }
        return ans;
   }
};

int main(int argc, const char* argv[]) {
    Solution s;
    ListNode *head;
    ListNode *current;
    for (size_t i = 0; i < 10; i++)
    {
        ListNode *node = new ListNode(i);
        if (head == nullptr)
        {
            head = node;
            current = head;
        }
        else
        {
            current->next = node;
            current = node;
        }
    }
    
    vector<int> ans = s.reversePrint(head);
    for (vector<int>::iterator itr = ans.begin(); itr != ans.end(); ++itr)
    {
        cout<<*itr<<endl;
    }
    return 0;
}