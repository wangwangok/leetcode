#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, int> floormap;
public:
    int jumpFloor(int number) {
        int result = floormap[number];
        if (result > 0)
        {
            return result;
        }
        
        if (number == 0 || number == 1)
        {
            return 1;
        }
        result = jumpFloor(number - 2) + jumpFloor(number - 1);
        floormap[number] = result;
        return result;
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    int result = s.jumpFloor(4);
    cout<<result<<endl;
    return 0;
}