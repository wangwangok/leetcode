#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * 
     * @param numbers int整型vector 
     * @param target int整型 
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        vector<int> result;
        for (int i = 1; i <= numbers.size(); i++)
        {
            for (int j = 1; j <= numbers.size(); j++)
            {
                if ( j == i)
                {
                    continue;
                }
                
                if (numbers[i-1]+numbers[j-1] == target)
                {
                   result.insert(result.begin(), {i, j}); 
                   return result;
                }
            }
        }
        return {-1, -1};
        /*
        if (numbers.size() <= 0)
        {
            return result;
        }
        unordered_map<int, int> rankMap;
        for (size_t i = 1; i <= numbers.size(); i++)
        {
            rankMap[numbers[i-1]] = i;
        }
        sort(numbers.begin(), numbers.end());
        for (vector<int>::iterator left = numbers.begin(), right = numbers.end()-1;
            right - numbers.begin() >= left - numbers.begin() && right >= numbers.begin() && left != numbers.end();
            )
        {
            int sum = *right + *left;
            if (sum == target)
            {
                result.insert(result.begin(), {rankMap[*left], rankMap[*right]});
                break;
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
            
        }
        return result;      
        */  
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    vector<int> nums{0,4,3,0};
    vector<int> result = s.twoSum(nums, 0);
    cout<<"[";
    for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i]<<", ";
    }
    cout<<"]";
    return 0;
}