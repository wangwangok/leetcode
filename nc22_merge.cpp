#include <iostream>

using namespace std;

class Solution {
public:
    void swap() {

    }
    void merge(int A[], int m, int B[], int n) {
        if (n <= 0) return;
        for (int i = 0; i < n; i++) {
            A[m+i] = B[i];
        }
        int a = 0;
        int b = m;
        for (;a<m;a++)
        {
            if (A[a] < A[b]) 
            {
                continue;
            }
            A[a] ^= A[b];
            A[b] ^= A[a];
            A[a] ^= A[b];
            for (int  i = b, j = i + 1; j < m + n; i++, j = i+1)
            {
                if (A[i] <= A[j]) break;
                A[i] ^= A[j];
                A[j] ^= A[i];
                A[i] ^= A[j];
            }
        }
    }
};

int main(int argc, const char *argv[]) {
    Solution s;
    int a[10] = {};
    int b[5] = {1,3,4,6,9};
    s.merge(a,0,b,5);
    int i = 0;
    while (i < 10)
    {
        cout<<a[i]<<endl;
        i++;
    }
    return 0;
}