#include <iostream>

using namespace std;
class Solution {
public:
    void repaceBlank(char *string, int *length) {
        if (string == nullptr) return;
        int count_of_blank = 0;
        int lenght_of_string = 0;
        for(int i = 0; *(string + i) != '\0';++i) {
            lenght_of_string++;
            if (*(string+i) == ' ') count_of_blank++;
        }
        int old_end_ptr = lenght_of_string - 1;
        int new_end_ptr = lenght_of_string + 2 * count_of_blank - 1;
        string = (char *)realloc(string, (new_end_ptr + 1) * sizeof(char));
        while(old_end_ptr <= new_end_ptr && old_end_ptr >= 0)
        {
            if (*(string+old_end_ptr) == ' ')
            {
                old_end_ptr--;
                *(string+new_end_ptr--) = '0';
                *(string+new_end_ptr--) = '2';
                *(string+new_end_ptr--) = '%';
                continue;
            }
            *(string + new_end_ptr) = *(string + old_end_ptr);
            old_end_ptr--;
            new_end_ptr--;
        }
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    int length = 0;
    char local[] = "We Are Happy ! ";
    char *str = (char *)malloc(strlen(local) * sizeof(char));
    strcpy(str, local);
    s.repaceBlank(str, &length);
    printf("%s\n", str);
    
    return 0;
}