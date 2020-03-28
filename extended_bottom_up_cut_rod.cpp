#include <iostream>
#include <vector>

using namespace std;
class Solution{
    private:
    vector<int> p;
    public:
    Solution() {
        int pt[10] = {1,5,8,9,10,17,17,20,24,30};
        vector<int> t(pt,pt+10);
        p = t;
    }

    int bottom_2_top(int idx) {
        size_t size = p.size();
        if (idx >= size)
        {
            return 0;
        }
        
        vector<int> r(size,0);
        for (size_t i = 1; i <= idx; i++)
        {
            int cost = 0;
            for (size_t j = 1; j <= i; j++)
            {
                cost = max(cost,p[j-1]+r[i-j]);
                
            }
            r[i] = cost;
        }
        return r[idx];
    }
};

int main() {
    Solution s;
    int value = s.bottom_2_top(4);
    cout<<value<<endl;
    return 0;
}
