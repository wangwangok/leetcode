#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <iterator>


/*

题目描述
设计LRU缓存结构，该结构在构造时确定大小，假设大小为K，并有如下两个功能
set(key, value)：将记录(key, value)插入该结构
get(key)：返回key对应的value值

[要求]
set和get方法的时间复杂度为O(1)
某个key的set或get操作一旦发生，认为这个key的记录成了最常使用的。
当缓存的大小超过K时，移除最不经常使用的记录，即set或get最久远的。
若opt=1，接下来两个整数x, y，表示set(x, y)
若opt=2，接下来一个整数x，表示get(x)，若x未出现过或已被移除，则返回-1
对于每个操作2，输出一个答案

* input: operators: [[1,1,1],[1,2,2],[1,3,2],[2,1],[1,4,4],[2,2]], k: 3
* output [1,-1]

map保存key和value；其中value为双向链表的结点；
双向链表的结点值为value；
*/

using namespace std;

class Solution {
    
    struct ListNode {
        struct ListNode *prev;
        struct ListNode *next;
        int key;
        int value;
    };
    
    unordered_map<int, ListNode *> maps;
    
    ListNode *head = nullptr; /// 双向链表的头指针
    ListNode *tail = nullptr; /// 双向链表的尾指针
    int list_count = 0;
    int list_length = 0;
    /// list
    bool dequeue(ListNode *node) {
        if (node == nullptr) return false;
        if (node == head) return true;
        ListNode *prev = node->prev;
        ListNode *next = node->next;
        if (next != nullptr) {
            next->prev = node->prev;
        }
        if (prev != nullptr) {
            prev->next = next;   
            if (prev->next == nullptr) tail = prev;
        }
        return true;
    }
    
    bool toHead(ListNode *node) {
        if (!dequeue(node)) return false;
        if (head == nullptr) {
            head = node;
            tail = node;
            return true;
        }
        node->next = head;
        node->prev = nullptr;
        head->prev = node;
        head = node;
        return true;
    }
    
    ListNode* removeTail() {
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
            return nullptr;
        }
        ListNode *node = tail;
        tail = tail->prev;
        tail->next = nullptr;
        return node;
    }
    
    /// map
    void set(int key, int value) {
         ListNode *node = maps[key];
        if (node != nullptr) {
            node->value = value;
            toHead(node);
            return;
        }
        while (list_length >= list_count) {
            ListNode *rmNode = removeTail();
            if (rmNode != nullptr) {
                maps.erase(rmNode->key);
                delete rmNode;
                list_length--;
            }
        }
        node = new ListNode();
        if (node == nullptr) return;
        node->key = key;
        node->value = value;
        if (toHead(node)) {
            maps[key] = node;
        }
        list_length++;
    }
    
    int get(int key) {
        ListNode *node = maps[key];
        if (node == nullptr) return -1;
        toHead(node);
        return node->value;
    }
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        // write code here
        if (k <= 0) return {};
        list_count = k;
        vector<int> result;
        for (vector<vector<int> >::iterator itr = operators.begin(); itr != operators.end(); ++itr) {
            vector<int> list = *itr;
            int op = *(list.begin());
            if (op == 1) {
                /// set
                set(list[1], list[2]);
            } else if (op == 2) {
                /// get
                result.push_back(get(list[1]));
            } else {
                continue;
            }
        }
        maps.clear();
        return result;
    }
};

int main(int argc, const char * argv[]) {
    /*
    
    */
    // [[],[],[],[],[],[]]
    cout<<"Hello"<<endl;
    ///*
    vector<vector<int>> ops{
        /// 测试用例1 -- 3
        // {1,1,1},
        // {1,2,2},
        // {1,3,2},
        // {2,1},
        // {1,4,4},
        // {2,2}

        /// 测试用例2 -- 3
        // {1,-324690837,-72487934},
        // {1,-723504364,-369145172},
        // {2,-324690837},
        // {1,724101438,-30727452},
        // {1,366967562,290286156},
        // {2,366967562},
        // {1,-21417066,-450706222},
        // {1,-484359960,-121414361},
        // {1,-629538923,-759874959},
        // {1,-461538894,749719150},
        // {1,-338664886,-3080586},
        // {2,522415046},
        // {1,134352387,-391032350},
        // {1,283492390,210901529},
        // {2,-328994470},
        // {2,-254674447},
        // {2,85161833},
        // {1,36899859,-561167545},
        // {1,-232060336,889831435},
        // {1,-848557701,-189598178},
        // {2,-81051921},
        // {1,57162090,-193776405},
        // {1,157908494,-941008658},
        // {2,-21417066}

        /// 测试用例3 --- 2
        // {1,1,1},
        // {1,2,2},
        // {2,1},
        // {1,3,3},
        // {2,2},
        // {1,4,4},
        // {2,1},
        // {2,3},
        // {2,4}

        /// 测试用例4 --- 3
        {1,1,1},
        {1,2,2},
        {2,1},
        {1,3,3},
        {2,2},
        {1,4,4},
        {2,1},
        {2,3},
        {2,4}
    };
    //*/
    Solution s;
    vector<int> result = s.LRU(ops, 3);
    cout<<"[";
    for (vector<int>::iterator itr = result.begin(); itr != result.end(); itr++)
    {
        cout<<*itr<<",";
    }
    cout<<"]"<<endl;
    return 0;
}