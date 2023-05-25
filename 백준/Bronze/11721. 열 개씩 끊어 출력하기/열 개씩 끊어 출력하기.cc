#include <cstdio>

using namespace std;

constexpr int MAX_STR = 100;

char str[MAX_STR + 1];

int main() {
    /*
     * Input.
     */
    scanf("%s", str);
    
    /*
     * Output.
     */
    for (int i = 0; str[i]; ++i) {
        if (0 == i % 10 && i) {
            printf("\n");
        }
        
        printf("%c", str[i]);
    }
    
    return 0;
}