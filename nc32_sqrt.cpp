#include <iostream>

using namespace std;

/**
 * 实现函数 int sqrt(int x).计算并返回x的平方根（向下取整）
 * 输入：2
 * 返回值：1
 */

class Solution {
public:
    /**
     * 
     * @param x int整型 
     * @return int整型
     */
    int sqrt(int a) {
        if (a < 0) return 0;
        /// f(x) = x^2 - a;
        /**
         
         切线方程：==> (y_1 - f(x))/(x_1 - x) = f'(x)
         ==> y = f(x) + f'(x) * (x_1 - x)
         与x轴相交之后：
         ==> 0 = f(x) + f'(x) * (x_1 - x)
         1、==> x_1 = x - f(x)/f'(x);
         */

        /**
         2、f(x) = x^2 的导函数为 f'(x) = 2x

         将2带入1中：x_1 = x - (x^2 - a)/2x 
         ==> x_1 = (x + a/x)/2
         */ 
        double x = a;

        while (fabs(a - (x*x)) > 0.0001)
        {
            x = (x + a/x) / 2.0;
        }
        return x;
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    cout<<s.sqrt(9)<<endl;
}