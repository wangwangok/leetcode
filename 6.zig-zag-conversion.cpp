/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 * 
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    struct ConvertNode{
        char value;
        ConvertNode *next;
        ConvertNode(char val):value(val),next(nullptr){}
        ConvertNode(char val, ConvertNode *node):value(val),next(node){}
        ConvertNode(){}
    };

    struct ConvertLinkedList{
        ConvertNode *root;
        ConvertNode *ptr;
        ConvertLinkedList() {
            root=nullptr;
            ptr=nullptr;
        }
    };

    string convert(string s, int numRows) {
       size_t size = s.size();
       if (1 >= numRows || size < numRows) return s; 
       vector<ConvertLinkedList*> result;
       for (int i = 0; i < numRows; i++)
       {
           ConvertLinkedList *list = new ConvertLinkedList();
           result.push_back(list);
       }
       cout<<result.size()<<endl;
       int numberOfPair = numRows + (numRows-2); 
       for(string::iterator itr = s.begin(); itr != s.end(); ++itr)
       {
           uint index = itr-s.begin();
           uint localIndex = index % numberOfPair;
           int rIdx = 0;
           if (localIndex < numRows)
           {
               rIdx = localIndex;
           }
           else
           {
               rIdx = numberOfPair - localIndex;
           }
           ConvertLinkedList *list = result[rIdx];
           ConvertNode *node = new ConvertNode(*itr);
           if (list->root == nullptr)
           {
               list->root = node;
               list->ptr = node;
           }
           else
           {
               list->ptr->next = node;
               list->ptr = node;
           }
       }
       string str;
       for (vector<ConvertLinkedList *>::iterator itr = result.begin(); itr != result.end(); ++itr)
       {
           ConvertNode *node = (*itr)->root;
           while (node)
           {
               str.push_back(node->value);
               node=node->next;
           }
       }
       return str;
    }
};
// @lc code=end
int main(int argc, const char *argv[]) {
    Solution s;
    string result = s.convert("PAYPALISHIRING",15);
    cout<<result<<endl;
    return 0;
}
