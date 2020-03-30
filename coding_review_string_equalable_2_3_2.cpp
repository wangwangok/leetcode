#include <iostream>

using namespace std;

int main(int argc, const char* argv[]) {
    const char *cV  = "Hello Wolrd";
    char str1[] = "Hello Wolrd";
    char str2[] = "Hello Wolrd";

    char *str3 = "Hello Wolrd";
    char *str4 = "Hello Wolrd";
    bool equal1 = str1 == str2;
    bool equal2 = str3 == str4;

    printf("%p\n", str1);
    printf("%p\n", str2);
    printf("%p\n", str3);
    printf("%p\n", str4);

    cout<<equal1<<" "<<equal2<<endl;
    return 0;
}