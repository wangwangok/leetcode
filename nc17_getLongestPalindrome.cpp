#include <iostream>
#include <string>

using namespace std;

/**
 * 对于一个字符串，请设计一个高效算法，计算其中最长回文子串的长度。给定字符串A以及它的长度n，请返回最长回文子串的长度。
 * 输入："abc1234321ab",12
 * 输出：7
 */

class Solution {
public:
/*
    int getLongestPalindrome(string A, int n) {
        // write code here
        int length = 0;
        bool continueloop = false;
        int i = 0;
        int step = 0;
        int max = length;
        while (i < n)
        {
            int j = n - 1 - step;
            if (j <= i) {
                length = length * 2 + (int)(j==i);
                break;
            }
            while (j > i)
            {
                if (A[i]==A[j]) 
                {
                    length++;
                    max = max < length ? length : max;
                    continueloop = true;
                    step = n - j;
                    break;
                }
                else 
                {
                    length = 0;
                    j--;
                }
            }
            i++;
        }
        return length;
    }
    */
   int getLongestPalindrome(string A, int n) {
       int p[n][n];
       int length = 1;
       for (int i = 0; i < n; i++)
       {
           p[i][i] = 1;
       }
       for (int i = 1; i < n; i++)
       {
           for (int j = i - 1; j >= 0; j--)
           {
               if (i - j == 1) /// 相邻
               {
                   if (A[i]==A[j]) 
                   {
                       p[j][i] = 1;
                       length = i - j + 1 > length ? i - j + 1 : length;
                   }
                   else
                   {
                       p[j][i] = 0;
                   }
               }
               else 
               {
                   /// 表示当前左右游标相邻已经是回文串
                   if (p[j+1][i-1] == 1 && A[i] == A[j])
                   {
                       p[j][i] = 1;
                       length = i - j + 1 > length ? i - j + 1 : length;
                   }
                   else 
                   {
                       p[j][i] = 0;
                   }
               }
           }
       }
       return length;
   }
};

int main(int argc, const char *argv[]) {
    Solution s;
    int length = s.getLongestPalindrome("dacbcbcabacaabcbcbdaaccacdddabdbcdcdbdabccbdababdaccbbbaccdaaacbbdcdadcacdbcbcacacaddbcbbcadccacdaabddacbcbbcdcadcbbcdddccdccdcbbbaabdadabdbbcbababacbbddbcdbdbbdabaaaaabacadbadbbadabccbbadbcdbcbaadbbddcacdbacadccbccdbacabacaacdbdcbcabbbccdadcbaccccccaaacbbbcbacdadaadcdbacaaadcbdccbcbcdacbababbc",295);
    // int length = s.getLongestPalindrome("abc1234321ab",12);
    cout<<length<<endl;
    return 0;
}