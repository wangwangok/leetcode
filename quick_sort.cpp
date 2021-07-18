#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    vector<int> sort(vector<int> input) {
        return partition(input, 0, input.size() - 1);
    }

private:
    void swap(vector<int> &input, int lhs, int rhs) {
        if (lhs >= input.size() || rhs >= input.size() || lhs == rhs)
        {
            return;
        }
        input[lhs] ^= input[rhs];
        input[rhs] ^= input[lhs];
        input[lhs] ^= input[rhs];
    }

    vector<int> partition(vector<int> &input, int lhs, int rhs) {
        if (lhs >= rhs)
        {
            return input;
        }
        int pivot = lhs;
        int start = lhs + 1;
        int end = rhs;

        while (start < end)
        {
            while (input[start] <= input[pivot] && start < rhs)
            {
                start++;
            }
            while (input[end] > input[pivot] && end >= lhs)
            {
                end--;
            }
            if (start <= end)
            {
                swap(input, start, end);
            }
        }
        if (input[pivot] > input[end])
        {
            swap(input, pivot, end);
        }
        partition(input, lhs, end-1);
        partition(input, end+1, rhs);
        return input;
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
    return 0;
}