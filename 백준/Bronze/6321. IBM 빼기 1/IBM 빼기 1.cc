#include <cstdio>

using namespace std;

constexpr int MAX_STR = 50;

int N;
char str[MAX_STR + 1];

int main() {
    /*
     * Input and Output.
     */
    scanf("%d", &N);
    
    for (int i = 1; N >= i; ++i) {
        scanf("%s", str);
        
        printf("String #%d\n", i);
        for (int j = 0; str[j]; ++j) {
            printf("%c", 'Z' == str[j] ? 'A' : str[j] + 1);
        }
        printf("\n\n");
    }
    
    return 0;
}