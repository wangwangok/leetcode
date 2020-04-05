#include <iostream>
#include <vector>
using namespace std;
class CQueue {
    struct StackNode {
        int val;
        StackNode *next;
    };
    StackNode *stack1;
    StackNode *stack2;
    bool isEmpty(StackNode *top) {
        if (top == nullptr) return true;
        return false;
    }
public:
    CQueue() {
        stack1 = nullptr;
        stack2 = nullptr;
    }
    
    void appendTail(int value) {
        StackNode *node = new StackNode();
        node->val = value;
        if (stack1 == nullptr)
        {
            stack1 = node;
        }
        else 
        {
            node->next = stack1;
            stack1 = node;
        }
    }
    
    int deleteHead() {
        auto deleteCore = [this]() -> int {
            StackNode *temp = stack2;
            int val = stack2->val;
            stack2 = stack2->next;
            delete temp;
            return val;
        };
        if (stack2 == nullptr)
        {
            while (stack1)
            {
                StackNode *node = stack1;
                stack1 = stack1->next;
                if (stack2 == nullptr)
                {
                    node->next = nullptr;
                    stack2 = node;
                }
                else
                {
                    node->next = stack2;
                    stack2 = node;
                }
            }
        }
        if (stack2 != nullptr)
        {
            return deleteCore();
        }
        return -1;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * 
 */
 int main(int argc, const char* argv[]) {
     int value =2;
     vector<int> nums1{1,3,2};
     CQueue* obj = new CQueue();
     for (size_t i = 0; i < nums1.size(); i++)
     {
        obj->appendTail(nums1[i]);
     }
     cout<<"delete: "<<obj->deleteHead()<<endl;
     vector<int> nums2{6,4,5};
     for (size_t i = 0; i < nums2.size(); i++)
     {
        obj->appendTail(nums2[i]);
     }
     cout<<"delete: "<<obj->deleteHead()<<endl;
     cout<<"delete: "<<obj->deleteHead()<<endl;
     cout<<"delete: "<<obj->deleteHead()<<endl;
     cout<<"delete: "<<obj->deleteHead()<<endl;
     cout<<"delete: "<<obj->deleteHead()<<endl;
     return 0;
 }