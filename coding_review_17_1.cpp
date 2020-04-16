#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
/*
    vector<int> printNumbers(int n) {
        if (n <= 0) return {};

    }
    */
   void printNumbers(int n) {
        if (n <= 0) return;
        char *str = new char(n+1);
        memset(str,'0',n);
        int carryin = 0;
        bool overflow = false;
        while (!overflow)
        {
            /// 0000...0000
            /// 0000...0001
            /// 0000...0002
            /// 0000...0003
            /// ...
            /// 0000...0010
            /// 0000...0011
            for(int i = n - 1; i >= 0; i--)
            {
                int sum = str[i] - '0' + carryin;
                if (i == n -1)
                {
                    sum++; /// 每次更加个位数
                }
                
                if (sum >= 10)
                {
                    if (i == 0) 
                    {
                        overflow = true;
                        break;
                    }
                    else
                    {
                        sum = sum - 10;
                        str[i] = sum + '0';
                        carryin = 1;
                    }
                }
                else 
                {
                    str[i] = sum + '0';
                    carryin = 0;
                }
            }
            if (overflow)
            {
                return;
            }
            
            bool visible_bit = false;
            const char *tmp_ptr = str;
            while (*tmp_ptr != '\0')
            {
                if (*tmp_ptr == '0' && visible_bit == false)
                {
                    tmp_ptr++;
                    continue;
                }
                visible_bit = true;
                cout<<*tmp_ptr;
                tmp_ptr++;
            }
            cout<<endl;
        }
        
   }
};

int main(int argc, const char* argv[]) {
    Solution s;
    s.printNumbers(2);
    return 0;
}