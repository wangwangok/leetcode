/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */
#include <iostream>
#include <unordered_map>
using namespace std;
// @lc code=start
class LRUCache {
private:
    struct LRUCacheNode {
        LRUCacheNode *next;
        LRUCacheNode *prev;
        int key;
        int value;

        LRUCacheNode() {

        }

        LRUCacheNode(const LRUCacheNode* node) {
            key = node->key;
            value = node->value;
            next = node->next;
            prev = node->prev;
        }

        ~LRUCacheNode() {

        }
    };
private:
    LRUCacheNode *head;
    LRUCacheNode *tail;
    unordered_map<int, LRUCacheNode*> map;
    int capacity;
private:

    void addNode(LRUCacheNode *node) {
        if(node == nullptr) return;
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(LRUCacheNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int removeTail() {
        if(head->next == tail && tail->prev == head) return -1;
        LRUCacheNode *lastNode = tail->prev;
        int key = lastNode->key;
        removeNode(lastNode);
        delete lastNode;
        return key;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new LRUCacheNode();
        tail = new LRUCacheNode();
        head->value = -1;
        head->key = -1;
        head->next = tail;
        head->prev = nullptr;
        tail->value = -1;
        tail->key = -1;
        tail->next = nullptr;
        tail->prev = head;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()) return -1;
        LRUCacheNode *node = map[key];
        removeNode(node);
        addNode(node);
        return node->value;
    }
    
    void put(int key, int value) {
        bool contain = false;
        if(map.find(key) != map.end()) contain = true;
        if(contain) {
            LRUCacheNode *node = map[key];
            node->value = value;
            removeNode(node);
            addNode(node);
            return;
        }
        LRUCacheNode *node = new LRUCacheNode();
        if (node == nullptr)
        {
            return;
        }
        if (map.size() >= capacity)
        {
            int key = removeTail();
            if (key >= 0)
            {
                map.erase(key);
            }
        }
        node->value = value;
        node->key = key;
        addNode(node);
        map.insert(make_pair(key, node));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main(int argc, const char* argv[]) {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    int value1 = cache.get(1);       // 返回  1
    cout<<"value1: "<<value1<<endl;
    cache.put(3, 3);    // 该操作会使得密钥 2 作废
    int value2 = cache.get(2);       // 返回 -1 (未找到)
    cout<<"value2: "<<value2<<endl;
    cache.put(4, 4);    // 该操作会使得密钥 1 作废
    int value3 = cache.get(1);       // 返回 -1 (未找到)
    cout<<"value3: "<<value3<<endl;
    int value4 = cache.get(3);       // 返回  3
    cout<<"value4: "<<value4<<endl;
    int value5 = cache.get(4);       // 返回  4  
    cout<<"value5: "<<value5<<endl;
    return 0;
}

