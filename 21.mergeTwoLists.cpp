struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *result = nullptr, *node = nullptr;
        ListNode *l1node = list1, *l2node = list2;
        while (l1node && l2node)
        {
            ListNode *temp = nullptr;
            if (l1node->val < l2node->val) {
                temp = l1node;
                l1node = l1node->next;
            } else {
                temp = l2node;
                l2node = l2node->next;
            }
            if (result == nullptr) {
                result = node = temp;
            } else {
                node->next = temp;
                node = temp;
            }
        }
        ListNode *temp = l1node ? l1node : (l2node ? l2node : nullptr);
        while (temp)
        {
            if (result == nullptr) {
                result = node = temp;
            } else {
                node->next = temp;
                node = temp;
            }
            temp = temp->next;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
