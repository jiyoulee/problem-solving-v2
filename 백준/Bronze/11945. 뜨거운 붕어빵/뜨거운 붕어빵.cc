#include <cstdio>

using namespace std;

constexpr int MAX_M = 10;

int N, M;
char str[MAX_M + 1];

int main() {
    /*
     * Input.
     */
    scanf("%d%d", &N, &M);
    
    /*
     * Output.
     */
    while (N--) {
        scanf("%s", str);
        
        for (int i = M - 1; 0 <= i; --i) {
            printf("%c", str[i]);
        }
        printf("\n");
    }
    
    return 0;
}