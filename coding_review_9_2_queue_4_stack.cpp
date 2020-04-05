#include <iostream>
#include <vector>
using namespace std;
class Stack {
    struct Queue {
    private:
        struct QueueNode{
            int val;
            QueueNode *next;
        };

        QueueNode *tail;
        QueueNode *front;
    public:
        Queue() { tail = nullptr; front = nullptr; }
        void enqueue(int val) {
            QueueNode *node = new QueueNode();
            node->val = val;
            node->next = nullptr;
            if (tail==nullptr)
            {
                front = tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }
        }

        int dequeue() {
            if (front == nullptr)
            {
                return -1;
            }
            int val = front->val;
            QueueNode *temp = front;
            front = front->next;
            if (front == nullptr)
            {
                tail = nullptr;
            }
            
            delete temp;
            return val;
        }
        
        bool isEmpty() {
            return front == nullptr;
        }

        bool isTail() {
            return front==tail && tail != nullptr;
        }
    };
    Queue queue1;
    Queue queue2;
    Queue *empty_queue;
    Queue *non_empty_queue;
public:
    Stack() {
        empty_queue = &queue1;
        non_empty_queue = &queue2;
    }
    void push(int val) {
        /// 插入
        non_empty_queue->enqueue(val);
    }

    int pop() {
        Queue *queue = non_empty_queue;
        while (non_empty_queue->isTail() == false)
        {
            int val = non_empty_queue->dequeue();
            empty_queue->enqueue(val);
        }
        int val = non_empty_queue->dequeue();
        non_empty_queue = empty_queue;
        empty_queue = queue;
        return val;
    }
};

int main(int argc, const char* argv[]) {
    vector<int> nums1{1,3,2};
    Stack stack;
    for (size_t i = 0; i < nums1.size(); i++)
    {
        stack.push(nums1[i]);
    }
    cout<<"pop: "<<stack.pop()<<endl;
    cout<<"pop: "<<stack.pop()<<endl;
    vector<int> nums2{6,4,5};
    for (size_t i = 0; i < nums1.size(); i++)
    {
        stack.push(nums2[i]);
    }
    cout<<"pop: "<<stack.pop()<<endl;
    cout<<"pop: "<<stack.pop()<<endl;
    cout<<"pop: "<<stack.pop()<<endl;
    cout<<"pop: "<<stack.pop()<<endl;
    return 0;
}