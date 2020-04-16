#include <iostream>

using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        /*
        uint32_t mask = 1;
        while (mask)
        {
            if ((n&mask) == mask)
            {
                count++;
            }
            mask = mask << 1;
        }
        return count;
        */
       /// n - 1会将n右边的0全部置为1，而且n值中最右边的1会被置为0；
       /// 将n-1与n进行按位与之后，n中最右边的1，及其之后的的位都会被置为0；
       while (n)
       {
           count = count + 1;
           n = (n - 1) & n;
       }
       
       return count;
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    int count = s.hammingWeight(0xfffffffd);
    cout<<count<<endl;
    return 0;
}