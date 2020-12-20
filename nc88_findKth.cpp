#include <iostream>
#include <vector>

using namespace std;

class Finder {
public:
/// 快排
    void swap(vector<int> &a, int left, int right) {
        if (left >= a.size() || right >= a.size() || left == right)
        {
            return;
        }
        a[left] ^= a[right];
        a[right] ^= a[left];
        a[left] ^= a[right];
    }

    int partition(vector<int> &a, int start, int end) {
        int pivot = a[end];
        int i = start - 1;
        for (int j = start; j < end; j++) {
            if (a[j] >= pivot) continue;
            ++i;
            swap(a, i, j);
        }
        swap(a, i+1, end);
        return i + 1;
    }

    void quick_sort(vector<int> &a, int start, int end) {
        if (start >= end)
        {
            return;
        }
        
        int result = partition(a, start, end);
        quick_sort(a, result + 1, end);
        quick_sort(a, start, result -1);
    }
    int findKth(vector<int> a, int n, int k) {
        if (a.size() <= 0 || k > n)
        {
            return -1;
        }
        quick_sort(a, 0, n-1);        
        cout<<"[";
        for (size_t i = 0; i < a.size(); i++)
        {
            cout<<a[i]<<", ";
        }
        cout<<"]"<<endl;
        return a[n - k];
    }
};

int main(int argc, const char * argv[]) {
    Finder f;
    vector<int> a{2,1,37,3,4,6};
    int result = f.findKth(a, a.size(), a.size());
    cout<<"result: "<<result<<endl;
    return 0;
}