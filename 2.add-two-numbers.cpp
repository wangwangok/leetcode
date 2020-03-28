/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* result_node = nullptr;
       ListNode* pivot = nullptr;
       ListNode* l1_temp = l1;
       ListNode* l2_temp = l2;
       int carry = 0;
       while (1)
       {
           if (l1_temp == nullptr && l2_temp == nullptr && carry == 0)
           {
               break;
           }
           int result = 0;
          if (l1_temp != nullptr)
          {
              result += l1_temp->val; 
              l1_temp = l1_temp->next;
          }
          if (l2_temp != nullptr)
          {
              result += l2_temp->val;
              l2_temp = l2_temp->next;
          }
          result += carry;
          carry = 0;
          if (result >= 10)
          {
             carry = 1;
             result = result - 10;    
          }
          ListNode *temp_node = new ListNode(result);                
          if (temp_node == nullptr)
          {
              break;
          }
          if (result_node == nullptr)
          {
              result_node = temp_node;
              pivot = result_node;
          } else {
             pivot->next = temp_node;    
             pivot = temp_node;
          } 
       }
       return result_node;
    }
};
// @lc code=end

