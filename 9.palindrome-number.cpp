/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0 || (x !=0 && x%10 == 0)) {
             return false;
        }
        int palindore = 0;
        int temp = x;
        while (temp > palindore)
        {
            palindore = palindore*10+temp%10;
            temp=temp/10;
        }
        return (palindore==temp) || (temp==palindore/10);
    }
};
// @lc code=end

