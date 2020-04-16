#include <iostream>

using namespace std;

class Solution {
public:
    /*
    double myPow(double x, int n) {
        bool signed_ = false;
        unsigned int exp = 0;
        if (n < 0)
        {
            signed_ = true;
            exp = (unsigned int)(-n);
        }
        else 
        {
            exp = n;
        }
        if (signed_ && x == 0.0)
        {
            return 0.0;
        }
        double ans = 1.0;
        for (unsigned int i = exp; i > 0;i--) 
        {
            ans *= x;
        }
        if (signed_) ans = 1/ans;
        return ans;
    }
    */
   double corePow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        double ans = myPow(x, n>>1);
        ans *= ans;
        if ((n & 0x1) == 0x1)
        {
            ans *= x;
        }
        return ans;
   }

   double myPow(double x, int n) {
       if (n == 0.0)
       {
           return 0.0;
       }
       long exp = 0;
        if (n < 0)
        {
            exp = -n;
            x = 1/x;
        }
        else 
        {
            exp = n;
        }
        double ans = x;
        while (exp > 0)
        {
            if ((exp & 0x1) == 0x1) ans = x * ans; /// 奇数一个x
            x = x * x; /// 偶数两个x相乘
            exp = exp>>1;
        }
        return ans;
   }
   
};

int main(int argc, const char* argv[]) {
    Solution s;
    cout<<s.myPow(2.00000,-2147483648)<<endl;
    return 0;
}