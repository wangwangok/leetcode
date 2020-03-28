#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    void swap(vector<int>& items, int lhs, int rhs) {
        size_t size = items.size();
        if (lhs >= size || rhs >= size)
        {
            return;
        }
        int temp = items[lhs];
        items[lhs] = items[rhs];
        items[rhs] = temp;
    }

    vector<int> quickSort(vector<int> *items, int start, int end) {
        vector<int> results;
        if (items->size() <= 1 || start >= end)
        {
            return *items;
        }
        results = (*items);
        int pivot = results[start];
        int i = start+1;
        int j = end;
        while (i < j)
        {
            while (results[i] <= pivot)
            {
                i++;
            }
            
            while (results[j] > pivot)
            {
                j--;
            }
            if (i < j)
            {
                swap(results,i,j);
            }
        }
        if (results[j] < pivot)
        {
            swap(results,j,start);
        }
        results = quickSort(&results,start,j-1);
        results = quickSort(&results,j+1,end);
        return results;
    }

    void logVector(vector<int> vec){
        for (vector<int>::iterator i = vec.begin(); i != vec.end(); ++i)
        {
            cout<<*i<<" ";
        }
        cout<<endl;
    }
};

int main(int argc, const char* argv[]) {
    //vector<int> items = {3,4,1,5,7,8,9}; /// c++17
    int temp[] = {3,4,1,5,7,9,2,11};
    vector<int> *items = new vector<int>(temp,temp+8);
    Solution s;
    vector<int> result = s.quickSort(items,0,items->size()-1);
    cout<<"logout:"<<endl;
    s.logVector(result);
    
    return 0;
}