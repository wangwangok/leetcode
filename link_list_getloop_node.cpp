/// 两个无环单链表，找出交点
#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int val):val(val),next(nullptr){}
};

class Solution {
public:
    Node* link(Node *link1, Node *link2) {
        if(link1 == nullptr || link2 == nullptr) return nullptr;
        /// 找到第一个链表的尾结点，由于他们相交，那么尾部结点肯定相同
        
        /// 依次顺序遍历两个链表，进行结点对比，O(mxn)
        
        Node *link1_lead = link1;
        Node *link2_lead = link2;
        /*
        while(link1_lead) {
            Node *temp = link2_lead;
            while (temp)
            {
                if (link1_lead == temp)
                {
                    return link1_lead;
                }
                temp = temp->next;
            }
            link1_lead = link1_lead->next;
        }
        return nullptr;
        */

        /// 跑圈
        while (link1_lead -> next)
        {
            link1_lead = link1_lead->next;
        }
        link1_lead->next = link2;

        Node *rhs = link1_lead;
        Node *lhs = link2;

        while (rhs != lhs)
        {
            lhs = lhs->next->next;
            rhs = rhs->next;
        }
        return rhs;
    }
    
    /*
    size_t link2_length; /// 较小的
    size_t link1_length; /// 较长的
    Node *head = link1;
    while (link1_length != link2_length)
    {
        head = head->next;
        link1_length--;
    }
    for(;;){}
    */

};

int main(int argc, const char*argv[]) {
    Node *node0 = new Node(0);
    Node *node1 = new Node(1);
    node0->next = node1;
    Node *node2 = new Node(2);
    node1->next = node2;
    Node *node3 = new Node(3);
    node2->next = node3;
    Node *node4 = new Node(4);
    node3->next = node4;

    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    node5->next = node6;
    Node *node7 = new Node(7);
    node6->next = node7;
    node7->next = node3;

    Node *link1 = node0;
    Node *link2 = node5;

    Solution s;
    Node *node = s.link(link1,link2);
    cout<<node->val<<endl;
    return 0;
}

