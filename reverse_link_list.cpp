#include <iostream>

using namespace std;

struct link_node{
    int value;
    link_node *next;

    link_node(int val, link_node *nxt) {
        value = val;
        next = nxt;
    }
};

link_node* reverse(link_node *lead) {
    if (lead == nullptr)
    {
        return nullptr;
    }
    link_node *trail, *middle;
    middle = nullptr;
    while (lead)
    {
        trail = middle;
        middle = lead;
        lead = lead->next;
        middle->next = trail;
    }
    return middle;
}

int main(int argc, const char* argv[]) {
    link_node *node6 = new link_node(5, nullptr);
    link_node *node5 = new link_node(4, node6);
    link_node *node4 = new link_node(3, node5);
    link_node *node3 = new link_node(2, node4);
    link_node *node2 = new link_node(1, node3);
    link_node *node1 = new link_node(0, node2);
    
    link_node* header = reverse(node1);

    for (link_node *lead = header; lead != nullptr; lead = lead -> next)
    {
        cout<<lead->value<<endl;
    }
    
}