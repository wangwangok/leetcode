#include <iostream>

using namespace std;
class Solution {
public:
    /// a有足够的空间
    void mergeSortedList(int a[],const int b[], int a_length, int b_length, int a_total_length) {
        int total_length = a_length + b_length;
        if (total_length > a_total_length) return;
        int insert_ptr = total_length - 1;
        
        
        for (int a_ptr = a_length - 1, b_ptr = b_length - 1;(a_ptr >= 0 || b_ptr >= 0) && insert_ptr >= 0 ; insert_ptr--)
        {
            if (a_ptr < 0) 
            {
                *(a+insert_ptr) = b[b_ptr]; 
                b_ptr--; 
                continue;
             }
            if (b_ptr < 0) {
                *(a+insert_ptr) = a[a_ptr]; 
                a_ptr--; 
                continue;
            }
            if (a[a_ptr] > b[b_ptr]) {
                *(a+insert_ptr) = a[a_ptr]; 
                a_ptr--;
            }
            else 
            {
                *(a+insert_ptr) = b[b_ptr]; 
                b_ptr--;
            }
        }
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    int a[10] = {1,3,5,7,9};
    int b[4] = {2,4,6,8};
    s.mergeSortedList(a,b,5,4,10);
    for (int i = 0; i < 10; i++)
    {
        cout<<a[i]<<endl;
    }
    
    return 0;
}