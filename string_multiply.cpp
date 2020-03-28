#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        size_t num1_size = num1.size();
        size_t num2_size = num2.size();

        if (num1_size <= 0 || num2_size <= 0)
        {
            return "";
        }
        vector<int> multiply_result(num1_size+num2_size, 0);
        for (string::const_reverse_iterator multiplier_itr = num1.rbegin(); multiplier_itr != num1.rend(); ++multiplier_itr)
        {
            int carry_in = 0;
            int multiplier_index = multiplier_itr - num1.rbegin();
            int multiplier_num = *multiplier_itr - '0';
            string::const_reverse_iterator multiplicand_end_itr = num2.rend();
            for (string::const_reverse_iterator multiplicand_itr = num2.rbegin(); multiplicand_itr != multiplicand_end_itr; ++multiplicand_itr)
            {
                int multiplicand_index = multiplicand_itr - num2.rbegin();
                int index = multiplier_index + multiplicand_index;
                int multiplicandr_num = *multiplicand_itr - '0';
                int old_value = multiply_result[index];
                int num_result = multiplier_num * multiplicandr_num + carry_in + old_value;
                int num_bit = num_result % 10;
                carry_in = num_result / 10;
                multiply_result[index] = num_bit;
                if (multiplicand_itr == multiplicand_end_itr - 1)
                {
                    multiply_result[index+1] = carry_in;
                }
            }
        }
        string result;
        bool append = false;
        for (vector<int>::reverse_iterator itr = multiply_result.rbegin(); itr != multiply_result.rend(); itr++)
        {
            if (append == false && *itr == 0)
            {
                 continue;
            }
            append = true;
            char chr = *itr + '0';
            result.push_back(chr);
        }
        if (result.size() <= 0)
        {
            result = "0";
        }
        return result;
    }
};

int main(int argc, const char* argvp[]) {
    Solution s;
    string result = s.multiply("9133","0");
    cout<<result<<endl;
    return 0;
}