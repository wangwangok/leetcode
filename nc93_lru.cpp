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
private:
    struct LinklistNode {
       LinklistNode *prev;
       LinklistNode *next;
       int key;
       int value;
       
       LinklistNode(int k, int v):key(k) ,value(v), prev(nullptr), next(nullptr){}
    };

    LinklistNode *head = nullptr;
    LinklistNode *tail = nullptr;

    int listCount = 0;

    void insertNode(LinklistNode *node) {
        if (node == nullptr || node == head || node == tail)
        {
            return;
        }
        listCount++;
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    LinklistNode* insertValue(int key, int value) {
        LinklistNode *node = new LinklistNode(key, value);
        insertNode(node);
        return node;
    }

    void deleteTail() {
        if (tail->prev == head)
        {
            return;
        }
        LinklistNode *temp = tail->prev;
        tail->prev = temp->prev;
        temp->prev->next = tail;
        temp->next = nullptr;
        temp->prev = nullptr;
        maps.erase(temp->key);
        listCount--;
    }

    void updateNode(LinklistNode *node) {
        if (node == nullptr || node == head || node == tail)
        {
            return;
        }
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->next = nullptr;
        node->prev = nullptr;
        /// 插入到头部
        insertNode(node);
        /// 只更新，不增加计数
        listCount--;
    }

    unordered_map<int, LinklistNode *> maps;
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        if (k<1)
        {
            return {};
        }
        
        if (head == nullptr)
        {
            head = new LinklistNode(0,0);
            tail = new LinklistNode(0,0);
            head->next = tail;
            tail->prev = head;
        }
        
        // write code here
        vector<int> result;
        // k 为 缓存大小
        for (vector<vector<int> >::iterator itr = operators.begin(); itr != operators.end(); itr++)
        {
            vector<int> cur_op = *itr;
            int key = cur_op[1];
            if (cur_op[0] == 1)
            { /// set
                if (cur_op.size() < 3 )
                {
                    continue;
                }
                int value = cur_op[2];
                if (maps.find(key) != maps.end())
                {
                    LinklistNode *node = maps[key];
                    node->value = value;
                    updateNode(node);
                }
                else
                {
                    if (listCount >= k)
                    {
                        deleteTail();
                    }
                    LinklistNode *node = insertValue(key, value);
                    maps[key] = node;
                }
            }
            else if (cur_op[0] == 2)
            { /// get
                if (cur_op.size() < 2 )
                {
                    continue;
                }
                if (maps.find(key) != maps.end())
                {
                    LinklistNode *node = maps[key];
                    updateNode(node);
                    result.push_back(node->value);
                }
                else
                {
                    maps.erase(key);   
                    result.push_back(-1);
                }
            }
        }
       return result; 
    }
};

int main(int argc, const char * argv[]) {
    /*
    
    */
    // [[],[],[],[],[],[]]
    cout<<"Hello"<<endl;
    /*
    vector<vector<int>> ops{
        {1,1,1},
        {1,2,2},
        {1,3,2},
        {2,1},
        {1,4,4},
        {2,2},
        };
    */
    ///*
    vector<vector<int>> ops{
        {1,-324690837,-72487934},
        {1,-723504364,-369145172},
        {2,-324690837},
        {1,724101438,-30727452},
        {1,366967562,290286156},
        {2,366967562},
        {1,-21417066,-450706222},
        {1,-484359960,-121414361},
        {1,-629538923,-759874959},
        {1,-461538894,749719150},
        {1,-338664886,-3080586},
        {2,522415046},
        {1,134352387,-391032350},
        {1,283492390,210901529},
        {2,-328994470},
        {2,-254674447},
        {2,85161833},
        {1,36899859,-561167545},
        {1,-232060336,889831435},
        {1,-848557701,-189598178},
        {2,-81051921},
        {1,57162090,-193776405},
        {1,157908494,-941008658},
        {2,-21417066}
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