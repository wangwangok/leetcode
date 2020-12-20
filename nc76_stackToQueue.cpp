#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            
        }
        if (stack2.empty()) return -1;
        int result = stack2.top();
        stack2.pop();
        return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(int argc, const char* argv[]) {
    Solution s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    return 0;
}