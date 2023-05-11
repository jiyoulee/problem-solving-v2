#include <cstdio>
#include <cctype>

using namespace std;

constexpr int MAX_STR = 20;

int N;
char str[MAX_STR + 1];

int main() {
    /*
     * Input and Output.
     */
    for (scanf("%d", &N); N--; ) {
        scanf("%s", str);
        
        for (int i = 0; str[i]; ++i) {
            printf("%c", tolower(str[i]));
        }
        printf("\n");
    }
        
    return 0;
}