#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

/**
 *  给定一个字符串数组，再给定整数k，请返回出现次数前k名的字符串和对应的次数。
    返回的答案应该按字符串出现频率由高到低排序。
    
    如果不同的字符串有相同出现频率，按字典序排序。
    
    对于两个字符串，大小关系取决于两个字符串从左到右第一个不同字符的 ASCII 值的大小关系。
    比如"ah1x"小于"ahb"，"231"<”32“
    
    字符仅包含数字和字母

* [要求]
    如果字符串数组长度为N，时间复杂度请达到O(NlogK)
* 输入：["a","b","c","b"],2
* 输出：[["b","2"],["a","1"]]
* 说明："b"出现了2次，记["b","2"]，"a"与"c"各出现1次，但是a字典序在c前面，记["a","1"]，最后返回[["b","2"],["a","1"]]
* ----
* 输入：["123","123","231","32"],2
* 输出：[["123","2"],["231","1"]]
* 说明："123"出现了2次，记["123","2"]，"231"与"32"各出现1次，但是"231"字典序在"32"前面，记["231","1"]，最后返回[["123","2"],["231","1"]] 
*/

class Solution {
public:
    /**
     * return topK string
     * @param strings string字符串vector strings
     * @param k int整型 the k
     * @return string字符串vector<vector<>>
     */
    vector<vector<string>> topKstrings(vector<string>& strings, int k) {
        if (strings.size() <= 0) return {};
        if (strings.size() < k) return {};
        unordered_map <string, int >map;
        vector<pair<string, int> > ordered_list;
        ordered_list.push_back(make_pair("",0));
        for (vector<string>::iterator itr = strings.begin(); itr != strings.end(); itr++) {
            int v = map[*itr];
            map[*itr] = v+1;
        }
        for (unordered_map<string, int>::iterator itr = map.begin(); itr != map.end(); ++itr) {
            pair<string, int> v = *itr;
            heap_insert(ordered_list, v);
        }
        int length = ordered_list.size() < k ? ordered_list.size() : k;
        vector<vector<string> > result;
        for (int i = 0; i < length; i++) {
            pair<string, int> p = heap_delete(ordered_list);
            if (p.second == 0)
            {
                continue;
            }
            vector<string> v;
            v.push_back(p.first);
            v.push_back(to_string(p.second));
            result.push_back(v);
        }
        return result;
    }

    void heap_insert(vector<pair<string, int> >& heap_array, pair<string, int>& kv) {
        if (heap_array.size() < 1) {
            return;
        }
        heap_array.push_back(kv);
        int child = heap_array.size() - 1;
        for (;child > 1 && asc(kv, heap_array[child/2]); child = child/2) {
            heap_array[child] = heap_array[child/2];
        }
        heap_array[child] = kv;
    }

    pair<string, int> heap_delete(vector<pair<string, int> > &heap_array) {
        int size = heap_array.size();
        if (size < 2) {
            return make_pair("",0);
        }
        pair<string, int> result = heap_array[1];
        if (size == 2) {
            return result;
        }
        int parent = 1;
        int child = 2;
        pair<string, int> temp = heap_array[size - 1];
        heap_array.pop_back();
        for(;child < heap_array.size();) {
            if (child+1 < heap_array.size() && asc(heap_array[child+1], heap_array[child])) {
                child++;
            }
            if (asc(temp,heap_array[child])) {
                break;
            }
            heap_array[parent] = heap_array[child];
            parent = child;
            child = 2 * child;
        }
        heap_array[parent] = temp;
        return result;
    }

    bool asc(pair<string, int> &p1, pair<string, int> &p2) {
        return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first);
    }
};

int main(int argc, const char *argv[]) {
    Solution s;
    vector<string> strings = {"a","b","c","b"};
    int k = 2;
    vector<vector<string> > result = s.topKstrings(strings, k);
    for (vector<vector<string> >::iterator itr = result.begin(); itr != result.end(); ++itr) {
        cout<< (*itr)[0] << ", " << (*itr)[1] << endl;
    }
    return 0;
}